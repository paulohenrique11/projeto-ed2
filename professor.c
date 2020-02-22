#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"
#include "departamento.h"


struct professor
{
    int matricula;
    char nome[40];
    char areaDeAtuacao[40];
    char titulacao[15];
    Professor * proximo;
};

Professor * CriaProfessor(char * nomeProf,char * areaDeAtuacao,char * titulacao,int mat)
{
    Professor * novoProf = (Professor*)malloc(sizeof(Professor));

    if(novoProf == NULL)
    {
        printf("MEMORIA INSUFICIENTE !!\n");
        exit(1);
    }

    strcpy(novoProf->nome,nomeProf);
    strcpy(novoProf->areaDeAtuacao,areaDeAtuacao);
    strcpy(novoProf->titulacao,titulacao);
    novoProf->matricula = mat;

    return novoProf ;
}

Professor * InsereProfessorAux(Professor * prim,Professor * profNovo)
{
    Professor * aux = prim;
    Professor * ant = NULL;

    while(aux != NULL && ComparaProfessor(aux,profNovo))
    {
        ant = aux;
        aux = aux->proximo;
    }

    //INSERE NO INICIO
    if(ant == NULL)
    {
        profNovo->proximo = aux;

        //CASO A INSERCAO SEJA NO INICIO NOS TEM UM NOVO PRIMEIRO PROFESSOR.
        return profNovo;
    }
    else
    {
        //INSERE NO MEIO
        ant->proximo = profNovo;
        profNovo->proximo = aux;
    }

    //CASO A INSERCAO SEJA NO MEIO DA LISTA NOS RETORNA O QUE ERA O PRIMEIRO PRA ATUALIZAR A LISTA.
    return prim;
}

int ComparaProfessor(Professor * pro,Professor * novo)
{
    if(strcmp(pro->nome,novo->nome) < 0)
    {
        return 1;
    }
    return 0;
}

int ComparaProfessorPresente(Professor * prim,Professor * profNovo)
{
    Professor * aux;

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        if(strcmp(aux->nome,profNovo->nome) == 0 && aux->matricula == profNovo->matricula)
        {
            return 1;
        }
    }

    return 0;
}

void ImpriProfessorMestrado(Professor * prim,char * sigla)
{
    Professor * aux;

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        if(strcmp(aux->titulacao,"Mestrado") == 0)
            printf("%s\n",aux->nome);
    }
}

void ImpriProfessorDoutorado(Professor * prim,char * sigla)
{
    Professor * aux;

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        if(strcmp(aux->titulacao,"Doutorado") == 0)
            printf("%s\n",aux->nome);
    }
}

void ImprimeNoArquivoProfessor(FILE * arq,Professor * prim,char *sigla)
{
    Professor * aux;
    fprintf(arq,"%s\n",sigla);

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        fprintf(arq,"%s\t%s\t%s\n",aux->nome,aux->areaDeAtuacao,aux->titulacao);
    }
}

void LiberaListaDeProfessores(Professor * prim)
{
    Professor * aux = prim, * aux1 = NULL;

    while(aux != NULL)
    {
        aux1 = aux->proximo;
        free(aux);
        aux = aux1;
    }
}

int VerificaNoProfessor(Professor * prim,int mat)
{
    Professor * aux;

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        if(aux->matricula == mat)
        {
            return 1;
        }
    }

    return 0;
}

int VerificaProfessor(Professor * prim,char * titulacao)
{
    Professor * aux;

    for(aux = prim ; aux != NULL ; aux = aux->proximo)
    {
        if(strcmp(aux->titulacao,titulacao) == 0)
        {
            //VERIFICA SE TEM PROFESSORES COM DOUTORADO
            return 1;
        }
    }
    return 0;
}










