#ifndef INSTITUICAO_H_INCLUDED
#define INSTITUICAO_H_INCLUDED

#include "departamento.h"

typedef struct arvn Arvn;
typedef struct instituicao Instituicao;

Instituicao * CriaInstituicao();
Arvn * ArvnCria(Instituicao *inst);

void InseriDepartamento(Arvn * a,Departamento * dep);

int VerificaTaCadastrado(Arvn * a,char * nomedep,char * sigla);

int VerificaDepartamentoCadastrado(Arvn * a,Departamento * dep);

Departamento * BuscaDepartamento(Arvn * a,char * sigla);

Departamento * BuscaPrimeiroDepartamento(Arvn * a);

void LiberaEstrutura(Arvn * a);

int ProfessorCadastrado(Arvn * a,int mat);

#endif // INSTITUICAO_H_INCLUDED
