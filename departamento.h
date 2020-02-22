#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

#include "professor.h"

typedef struct departamento Departamento;

Departamento * CriaDepartamento(char * NomeDep , char * Sigla);

Departamento * InseriDepartamentoAux1(Departamento * prim,Departamento * dep);

int VerificaTaCadastradoAux1(Departamento * prim,char * nomedep,char * sigla);

int VerificaDepartamentoCadastradoAux1(Departamento * prim,Departamento * dep);

Departamento * BuscaDepartamentoAux1(Departamento * prim,char * sigla);

void InsereProfessor(Departamento * DepartamentoBuscado,Professor * profnovo);

int VerificaProfessorCadastrado(Departamento * DepartamentoBuscado,Professor * profnovo);

void ImprimeProfessorMestrado(Departamento * DepartamentoBuscado);

void ImprimeProfessorDoutorado(Departamento * DepartamentoBuscado);

void SalvaDadosArquivo(Departamento * DepartamentoBuscado);

void FuncaoLiberaDepartamentos(Departamento * prim);

int VerificaNoDepartamento(Departamento *prim,int mat);

int buscaInformacao(Departamento * DepartamentoBuscado,char * titulacao);

#endif // DEPARTAMENTO_H_INCLUDED
