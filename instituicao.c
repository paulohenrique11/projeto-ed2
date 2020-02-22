#include <stdio.h>
#include <stdlib.h>
#include "instituicao.h"
#include "departamento.h"
#include "professor.h"

struct arvn
{
    Instituicao * ufersa;
};

struct instituicao
{
    Instituicao * prox;
    Departamento * prim;
};

Instituicao * CriaInstituicao()
{
    Instituicao * nova = (Instituicao*)malloc(sizeof(Instituicao));

    if(nova == NULL)
    {
        printf("MEMORIA INSUFICIENTE !!\n");
        exit(1);
    }

    nova->prox = NULL;
    nova->prim = NULL;

    return nova;
}

Arvn * ArvnCria(Instituicao * inst)
{
    Arvn * a = (Arvn*)malloc(sizeof(Arvn));

    if(a == NULL)
    {
        printf("MEMORIA INSUFICIENTE !!\n");
        exit(1);
    }

    a->ufersa = inst;

    return a;
}

static void InseriDepartamentoAux(Instituicao * ufersa,Departamento * dep)
{
    ufersa->prim = InseriDepartamentoAux1(ufersa->prim,dep);
}

void InseriDepartamento(Arvn * a,Departamento * dep)
{
    InseriDepartamentoAux(a->ufersa,dep);
}

static int VerificaTaCadastradoAux(Instituicao * ufersa,char * nomedep,char * sigla)
{
    return VerificaTaCadastradoAux1(ufersa->prim,nomedep,sigla);
}

int VerificaTaCadastrado(Arvn * a,char * nomedep,char * sigla)
{
    return VerificaTaCadastradoAux(a->ufersa,nomedep,sigla);
}

static int VerificaDepartamentoCadastradoAux(Instituicao * ufersa ,Departamento * dep)
{
    return VerificaDepartamentoCadastradoAux1(ufersa->prim,dep);
}

int VerificaDepartamentoCadastrado(Arvn * a,Departamento * dep)
{
    return VerificaDepartamentoCadastradoAux(a->ufersa,dep);
}

static Departamento * BuscaDepartamentoAux(Instituicao * ufersa ,char * sigla)
{
    return BuscaDepartamentoAux1(ufersa->prim,sigla);
}

Departamento * BuscaDepartamento(Arvn * a,char * sigla)
{
    return BuscaDepartamentoAux(a->ufersa,sigla);
}

static Departamento * BuscaPrimeiroDepartamentoAux(Instituicao * ufersa)
{
    return ufersa->prim;
}

Departamento * BuscaPrimeiroDepartamento(Arvn * a)
{
    return BuscaPrimeiroDepartamentoAux(a->ufersa);
}

static void LiberaEstruturaAux(Instituicao * ufersa)
{
    FuncaoLiberaDepartamentos(ufersa->prim);
}

void LiberaEstrutura(Arvn * a)
{


    LiberaEstruturaAux(a->ufersa);

    free(a->ufersa);
    free(a);
}

static int ProfessorCadastradoAux(Instituicao *ufersa ,int mat)
{
    return VerificaNoDepartamento(ufersa->prim,mat);
}

int ProfessorCadastrado(Arvn *a,int mat)
{
    return ProfessorCadastradoAux(a->ufersa,mat);
}
























