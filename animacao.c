#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "animacao.h"

//////////////////////////////////////////////-> ANIMAÇÃO <-//////////////////////////////////////////////

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}

void carregando(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        gotoxy(45,17);
        printf("CARREGANDO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacaoSaindo(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        gotoxy(45,17);
        printf("SAINDO");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

void animacaoSalvandoD(void)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        gotoxy(40,17);
        printf("SALVANDO DADOS");
        for(j=0; j<6; j++)
        {
            printf(".");
            Sleep(50);
        }
        Sleep(100);
        system("cls");
    }
}

