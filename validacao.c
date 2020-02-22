#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include <string.h>

char * LerNome(void)
{
    int teste;

    char  * Nome = (char *)malloc(80 * sizeof(char));

    teste = scanf(" %[^\n]",Nome);

    while(!teste || !verificaNome(Nome))
    {
        if(teste)
        {
            printf("\nO nome %s não é valido ",Nome);
        }

        else
        {
            printf("\nO nome introduzido não é valido. ");
        }
        printf("\nIntroduza um nome valido :");
        LimpaBufferV();
        teste = scanf(" %[^\n]",Nome);
    }
    LimpaBufferV();

    return Nome;
}

int verificaNome(char * nome)
{
    char nomeSemEspaco[60];

    int i,j = 0;

    int tamNome = strlen(nome);

    for(i = 0 ; i < tamNome ; i++)
    {
        if(nome[i] != ' ')
        {
            nomeSemEspaco[j] = nome[i];
            j++;
        }
    }

    nomeSemEspaco[j] = '\0';

    int letrasCont = 0;

    for(i = 0 ; i < strlen(nomeSemEspaco) ; i++)
    {
        if(( nomeSemEspaco[i] >= 'a' && nomeSemEspaco[i] <= 'z' )|| ( nomeSemEspaco[i] >= 'A' && nomeSemEspaco[i] <= 'Z' ))
        {
            letrasCont++;
        }
    }

    return(strlen(nomeSemEspaco) == letrasCont);
}

long unsigned LerValor(void)
{
    long valor;

    unsigned teste;

    teste = scanf("%ld",&valor);

    while(!teste || !VerificaValor(valor))
    {
        if(teste)
        {
            printf("\nO valor %ld nao e valido ",valor);
        }
        else
        {
            printf("\nO valor introduzido nao e valido. ");
        }
        printf("\nIntroduza um numero inteiro positivo :");
        LimpaBufferV();
        teste = scanf("%ld",&valor);
    }
    LimpaBufferV();

    return valor;
}

unsigned VerificaValor(int valor)
{
    return (valor >= 0);
}

void LimpaBufferV(void)
{
    (void)scanf("%*[^\n]");
    (void)getchar();
}



