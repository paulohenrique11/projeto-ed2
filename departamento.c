#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"
#include "professor.h"


struct departamento
{
    char nome[60];
    char sigla[10];
    Departamento * prox;
    Professor * prim;
};

Departamento * CriaDepartamento(char * NomeDep, char * Sigla)
{
    Departamento * novo = (Departamento*)malloc(sizeof(Departamento));

    if(novo == NULL)
    {
        printf("MEMORIA INSUFICIENTE !!\n");
        exit(1);
    }

    strcpy(novo->nome,NomeDep);
    strcpy(novo->sigla,Sigla);

    novo->prox = NULL;
    novo->prim = NULL;

    return novo;
}

Departamento * InseriDepartamentoAux1(Departamento * prim,Departamento * dep)
{
    dep->prox = prim;

    return dep;
}

int VerificaTaCadastradoAux1(Departamento * prim,char * nomedep,char * sigla)
{
    Departamento * aux ;

    for(aux = prim ; aux != NULL ; aux = aux->prox)
    {
        if(strcmp(aux->nome,nomedep) == 0 || strcmp(aux->sigla,sigla) == 0)
        {
            return 1 ;
        }
    }

    return 0 ;
}

int VerificaDepartamentoCadastradoAux1(Departamento * prim,Departamento * dep)
{
    Departamento * aux ;

    for(aux = prim ; aux != NULL ; aux = aux->prox)
    {
        if(strcmp(aux->nome,dep->nome) == 0 && strcmp(aux->sigla,dep->sigla) == 0)
        {
            return 1 ;
        }
    }

    return 0 ;
}

Departamento * BuscaDepartamentoAux1(Departamento * prim,char * sigla)
{
    Departamento * aux ;

    for(aux = prim ; aux != NULL ; aux = aux->prox)
    {
        if(strcmp(aux->sigla,sigla) == 0)
        {
            return aux;
        }
    }

    return NULL;
}

void InsereProfessor(Departamento * DepartamentoBuscado,Professor * profnovo)
{
    DepartamentoBuscado->prim = InsereProfessorAux(DepartamentoBuscado->prim,profnovo);
}

int VerificaProfessorCadastrado(Departamento * DepartamentoBuscado,Professor * profnovo)
{
    if(ComparaProfessorPresente(DepartamentoBuscado->prim,profnovo))
    {
        return 1;
    }

    return 0;
}

void ImprimeProfessorMestrado(Departamento * DepartamentoBuscado)
{
    Departamento * aux;

    for(aux = DepartamentoBuscado ; aux != NULL ; aux = aux->prox)
    {
        printf("%s\n",aux->sigla);
        if(aux->prim != NULL)
        {
            ImpriProfessorMestrado(aux->prim,aux->sigla);
        }
        printf("\n");
    }
    system("pause");
}

void ImprimeProfessorDoutorado(Departamento * DepartamentoBuscado)
{
    Departamento * aux ;

    for(aux = DepartamentoBuscado ; aux != NULL ; aux = aux->prox)
    {
        printf("%s\n",aux->sigla);
        if(aux->prim != NULL)
        {
            ImpriProfessorDoutorado(aux->prim,aux->sigla);
        }
        printf("\n");
    }
    system("pause");
}

void SalvaDadosArquivo(Departamento * DepartamentoBuscado)
{

    Departamento * aux;

    FILE *arq = fopen("saida.txt","wt");

    if(arq == NULL)
    {
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO !! \n");
        exit(1);
    }

    for(aux = DepartamentoBuscado ; aux != NULL ; aux = aux->prox)
    {
        if(aux->prim != NULL)
        {
            ImprimeNoArquivoProfessor(arq,aux->prim,aux->sigla);
        }


    }

    fclose(arq);
}

void FuncaoLiberaDepartamentos(Departamento * prim)
{
    Departamento * aux = prim, * aux1 = NULL;

    while(aux != NULL)
    {
        aux1 = aux->prox;
        LiberaListaDeProfessores(aux->prim);
        free(aux);
        aux = aux1;
    }
}

int VerificaNoDepartamento(Departamento *prim,int mat)
{
    Departamento * aux;

    for(aux = prim ; aux != NULL ; aux = aux->prox)
    {
        if(VerificaNoProfessor(aux->prim,mat) == 1)
        {
            return 1 ;
        }
    }
    return 0;
}

int buscaInformacao(Departamento * DepartamentoBuscado,char * titulacao)
{
    Departamento * aux = DepartamentoBuscado;

    while(aux != NULL)
    {
        if(VerificaProfessor(aux->prim,titulacao))
            return 1;

        aux = aux->prox;
    }
    return 0;
}



























