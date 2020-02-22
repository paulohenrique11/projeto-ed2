#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <stdarg.h>
#include "animacao.h"

void ApresentaMenu(int nItens,int menorOpcao,...)
{
    int i;


    va_list argumentos;

    va_start(argumentos,menorOpcao);

    for(i = 0; i < nItens; i++)
    {
        printf("|\t%c\t|\t%s\n",menorOpcao++,va_arg(argumentos,char *));
    }

    va_end(argumentos);
}

void LimpaBuffer(void)
{
    int valorlido;

    do
    {
        valorlido = getchar();
    }
    while((valorlido != '\n') && (valorlido != EOF));
}

int LerOpcao(int menorValor , int maiorValor)
{
    int op;

    while(1)
    {
        printf("\n\n\n Informe uma das opções acima: ");
        op = getchar();

        if(op >= menorValor && op <= maiorValor)
        {
            LimpaBuffer();
            break;
        }
        else
        {
            printf("\nOpção invalida .Tente novamente .");
            printf("A opção deve estar entre %c e %c.",menorValor,maiorValor);
            LimpaBuffer();
        }
    }

    return op;
}


















