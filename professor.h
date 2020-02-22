#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include <stdio.h>

typedef struct professor Professor;

Professor * CriaProfessor(char * nomeProf,char * areaDeAtuacao,char * titulacao,int mat);

Professor * InsereProfessorAux(Professor * prim,Professor * profNovo);

int ComparaProfessor(Professor * pro ,Professor * novo);

int ComparaProfessorPresente(Professor * prim,Professor * profNovo);

void ImpriProfessorMestrado(Professor * prim,char * sigla);

void ImpriProfessorDoutorado(Professor * prim,char * sigla);

void ImprimeNoArquivoProfessor(FILE * arq,Professor * prim,char *sigla);

void LiberaListaDeProfessores(Professor * prim);

int VerificaNoProfessor(Professor * prim,int mat);

int VerificaProfessor(Professor * prim,char * titulacao);

#endif // PROFESSOR_H_INCLUDED
