#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "instituicao.h"
#include "departamento.h"
#include "professor.h"
#include "animacao.h"
#include "validacao.h"
#include "menu.h"

//OPCAO DO MENU PRINCIPAL
#define TITULO_OPCAO1 "Cadastrar departamento"
#define TITULO_OPCAO2 "Cadastrar professor(a)"
#define TITULO_OPCAO3 "Listar professores com mestrado"
#define TITULO_OPCAO4 "Listar professores com doutorado"
#define TITULO_OPCAO5 "Salvar dados no arquivo"
#define TITULO_OPCAO6 "Sair do programa"

#define N_OPCAO 6
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'

//SUB MENU DA OPCAO 1
#define TITULO_OPCAO1_SUB_OPCAO1 "Cadastrar outro departamento"
#define TITULO_OPCAO1_SUB_OPCAO2 "Voltar para o menu principal"
//SUB MENU DA OPCAO 2
#define TITULO_OPCAO2_SUB_OPCAO1 "Cadastrar outro professor(a)"
#define TITULO_OPCAO2_SUB_OPCAO2 "Voltar para o menu principal"
//SUB MENU DA OPCAO 6
#define TITULO_OPCAO6_SUB_OPCAO1 "Salvar dados no arquivo ?"
#define TITULO_OPCAO6_SUB_OPCAO2 "Sair ?"

//NUMERO DE OPCOES DO SUB MENUS
#define N_OPCAO_SUB 2
//SUB MENU DA OPCAO 1
#define OPCAO1_SUB_OPCAO1 '1'
#define OPCAO1_SUB_OPCAO2 '2'
//SUB MENU DA OPCAO 2
#define OPCAO2_SUB_OPCAO1 '1'
#define OPCAO2_SUB_OPCAO2 '2'
//SUB MENU DA OPCAO 6
#define OPCAO6_SUB_OPCAO1 '1'
#define OPCAO6_SUB_OPCAO2 '2'

int main()
{
    setlocale(LC_ALL,"Portuguese");
    SetConsoleTitle("UFERSA - Universidade Federal Rural do Semi-Arido - Campus de Pau dos Ferros ");

    //CRIA A INSTITUICAO.
    Instituicao * inst = CriaInstituicao();
    Arvn * a = ArvnCria(inst);

    //DADOS DO DEPARTAMENTO
    char nomedep[80];
    char sigla[10];

    //DADOS DO PROFESSOR
    int mat;
    char nomeProf[40];
    char AreaDeAtuacao[40];
    char titulacao[15];

    int salvar = 0;
    int verifica;

    //MENU
    unsigned int saida = 0;
    unsigned char op;

    Departamento * DepartamentoBuscado;

    while(!saida)
    {
        printf(" ___________________________________________________________\n");
        printf("|               |                                           |\n");
        printf("|      Opção    |                    Funções                |\n");
        printf("|_______________|___________________________________________|\n");
        printf("|               |                                           |\n");
        ApresentaMenu(N_OPCAO,OPCAO1,TITULO_OPCAO1,
                      TITULO_OPCAO2,TITULO_OPCAO3,
                      TITULO_OPCAO4,TITULO_OPCAO5,
                      TITULO_OPCAO6);
        printf("|_______________|___________________________________________|\n");

        //LACO PARA DETALHES DO MENU NA LATERAL DIREITA
        int m;
        for(m = 6 ; m <= 11; m++)
        {
            gotoxy(61,m);
            printf("|");
        }

        op = LerOpcao(OPCAO1,OPCAO1 + N_OPCAO - 1);

        switch(op)
        {
        case OPCAO1 :

            system("cls");

            //CASO QUEIRA CADASTRAR VARIOS DEPARTAMENTOS EM SEQUENCIA.
            while(op != OPCAO1_SUB_OPCAO2)
            {
                //VERIFICA SE O DEPARTAMENTO JA TA CADASTRADO !!.
                do
                {
                    printf("Informe o nome do departamento : ");
                    //FUNCAO PARA VALIDAR OS DADOS.
                    strcpy(nomedep,LerNome());

                    printf("\nInforme a sigla do departamento : ");
                    //FUNCAO PARA VALIDAR OS DADOS.
                    strcpy(sigla,LerNome());

                    system("cls");


                    //FUNCAO VERIFICA SE O DEPARTAMENTO JA TA CADASTRADO.
                    verifica = VerificaTaCadastrado(a,nomedep,sigla);

                    if(verifica == 1)
                    {
                        int i;
                        for(i = 5 ; i > 0 ; i--)
                        {
                            //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                            system("color 04");
                            printf("\n\t\tOPS, Já tem um departamento com essa sigla ou com esse nome cadastrado .\n\t\t\tCadastrar um novo departamento em %i",i);
                            Sleep(1000);
                            system("cls");
                        }

                        system("color 07");
                    }

                    system("cls");
                }
                while(verifica != 0);

                //FUNCAO PARA CRIAR O DEPARTAMENTO.
                Departamento * dep = CriaDepartamento(nomedep,sigla);


                //FUNCAO PARA INSERIR O DEPARTAMENTO NA TABELA HASH.
                InseriDepartamento(a,dep);

                //FUNCAO PARA FERIFICAR SE FOI CADASTRADO COM SUCESSO.
                //RETORNA 1 CASO TENHA CADASTRADO COM SUCESSO E 0 CASO CONTRARIO.
                verifica = VerificaDepartamentoCadastrado(a,dep);


                if(verifica == 0)
                {
                    int i;
                    for(i = 5 ; i > 0 ; i--)
                    {
                        //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                        system("color 04");
                        printf("\n\t\tOPS, O departamento não foi cadastrado com sucesso .\n\t\t\tVocê sera redirecionado para a tela inicial em %i ",i);
                        Sleep(1000);
                        system("cls");
                    }
                    system("color 07");
                    op = OPCAO1_SUB_OPCAO2;
                }
                else
                {
                    //MENU PERGUNTANDO SE DESEJA CADASTRAR OUTRO DEPARTAMENTO OU VOLTAR PARA O MENU INICIAL.
                    printf(" ___________________________________________________________\n");
                    printf("|                                                           |\n");
                    printf("|      Departamento cadastrado com sucesso !!               |\n");
                    printf("|___________________________________________________________|\n");
                    printf("|               |                                           |\n");
                    ApresentaMenu(N_OPCAO_SUB,OPCAO1_SUB_OPCAO1,
                                  TITULO_OPCAO1_SUB_OPCAO1,
                                  TITULO_OPCAO1_SUB_OPCAO2);
                    printf("|_______________|___________________________________________|\n");

                    //LAÇO PARA DETALHES DO MENU NA LATERAL DIREITA
                    int m;
                    for(m = 6 ; m <= 7; m++)
                    {
                        gotoxy(61,m);
                        printf("|");
                    }

                    op = LerOpcao(OPCAO1_SUB_OPCAO1,OPCAO1_SUB_OPCAO1 + N_OPCAO_SUB - 1);
                }

                system("cls");

                //ANIMAÇÃO CARREGANDO
                carregando();

                system("cls");
            }

            system("cls");

            break;
        case OPCAO2 :

            system("cls");

            //ENTRA NO WHILE ABAIXO
            op = 0 ;

            //CASO QUEIRA CADASTRAR VARIOS PROFESSOR EM SEQUÊNCIA.
            while(op != OPCAO2_SUB_OPCAO2)
            {
                //VERIFICA SE O PROFESSOR JÁ ESTÁ CADASTRADO EM ALGUM DEPARTAMENTO.
                do
                {
                    printf("Informe o nome do professor(a) : ");
                    //FUNÇÃO PARA VALIDAR OS DADOS.
                    strcpy(nomeProf,LerNome());

                    printf("\nInforme a area de atuação : ");
                    //FUNÇÃO PARA VALIDAR OS DADOS.
                    strcpy(AreaDeAtuacao,LerNome());

                    printf("\nAtenção digitar Mestrado ou Doutorado !!!");
                    printf("\nInforme o titulo que possui : ");
                    //FUNÇÃO PARA VALIDAR OS DADOS.
                    strcpy(titulacao,LerNome());

                    printf("\nInforme a matricula do professor(a): ");
                    //FUNÇÃO PARA VALIDAR OS DADOS.
                    mat = LerValor();

                    printf("\nInforme a sigla do departamento onde deseja cadastrar : ");
                    //FUNÇÃO PARA VALIDAR OS DADOS.
                    strcpy(sigla,LerNome());

                    //FUNÇÃO VERIFICA SE O PROFESSOR ESTA CADASTRADO.
                    verifica = ProfessorCadastrado(a,mat);

                    system("cls");

                    if(verifica == 1)
                    {
                        int i;
                        for(i = 5 ; i > 0 ; i--)
                        {
                            //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                            system("color 04");
                            printf("\n\t\tOPS, Já tem um professor cadastrado com essa matricula .\n\t\t\tCadastrar um novo professor em %i",i);
                            Sleep(1000);
                            system("cls");
                        }
                        system("color 07");
                    }
                    system("cls");
                }
                while(verifica != 0);

                //FUNCAO PARA CRIAR O PROFESSOR.
                Professor * profnovo = CriaProfessor(nomeProf,AreaDeAtuacao,titulacao,mat);

                //FUNCAO PARA BUSCAR O DEPARTAMENTO.
                DepartamentoBuscado = BuscaDepartamento(a,sigla);

                if(DepartamentoBuscado != NULL)
                {
                    //FUNCAO PARA INSERIR O PROFESSOR NO DEPARTAMENTO NA TABELA HASH.
                    InsereProfessor(DepartamentoBuscado,profnovo);

                    //FUNCAO PARA VERIFICAR SE O PROFESSOR FOI CADASTRADO COM SUCESSO.
                    verifica = VerificaProfessorCadastrado(DepartamentoBuscado,profnovo);

                    //VERIFICA SE FOI CADASTRADO COM SUCESSO!!
                    //RETORNA 1 CASO TENHA CADASTRADO COM SUCESSO E 0 CASO CONTRARIO.
                    if(verifica == 0)
                    {
                        int i;
                        for(i = 5 ; i > 0 ; i--)
                        {
                            //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                            system("color 04");
                            printf("\n\t\tOPS, O professor não foi cadastrado com sucesso . \n\t\t\tVocê será redirecionado para a tela inicial em %i ",i);
                            Sleep(1000);
                            system("cls");
                        }
                        system("color 07");
                        op = OPCAO2_SUB_OPCAO2;
                    }
                    else
                    {
                        //MENU PERGUNTANDO SE DESEJA CADASTRAR OUTRO PROFESSOR OU VOLTAR PARA O MENU INICIAL.
                        printf(" ___________________________________________________________\n");
                        printf("|                                                           |\n");
                        printf("|      Professor cadastrado com sucesso !!                  |\n");
                        printf("|___________________________________________________________|\n");
                        printf("|               |                                           |\n");
                        ApresentaMenu(N_OPCAO_SUB,OPCAO2_SUB_OPCAO1,
                                      TITULO_OPCAO2_SUB_OPCAO1,
                                      TITULO_OPCAO2_SUB_OPCAO2);
                        printf("|_______________|___________________________________________|\n");

                        //LAÇO PARA DETALHES DO MENU NA LATERAL DIREITA
                        int m;
                        for(m = 6 ; m <= 7; m++)
                        {
                            gotoxy(61,m);
                            printf("|");
                        }

                        op = LerOpcao(OPCAO2_SUB_OPCAO1,OPCAO2_SUB_OPCAO1 + N_OPCAO_SUB - 1);
                    }
                }
                else
                {
                    int i ;

                    for(i = 5 ; i > 0 ; i--)
                    {
                        //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                        system("color 04");
                        printf("\n\t\t O departamento buscado nao foi encontrado . \n\t\tVocê será redirecionado para o menu inicial em %i",i);
                        Sleep(1000);
                        system("cls");
                    }
                    system("color 07");
                    op = OPCAO2_SUB_OPCAO2;
                }

                system("cls");

                //ANIMAÇÃO CARREGANDO
                carregando();

                system("cls");
            }

            system("cls");

            break;
        case OPCAO3 :

            system("cls");

            //ANIMAÇÃO CARREGANDO
            carregando();

            //FUNÇÃO PARA BUSCAR O PRIMEIRO DEPARTAMENTO.
            DepartamentoBuscado = BuscaPrimeiroDepartamento(a);

            //VERIFICA SE TEM DEPARTAMENTO NA INSTITUICAO
            if(DepartamentoBuscado != NULL)
            {
                //VERIFICA SE TEM ALGUM PROFESSOR COM MESTRADO
                if(buscaInformacao(DepartamentoBuscado,"Mestrado"))
                {
                    printf("PROFESSORES COM MESTRADO : \n\n");
                    //FUNÇÃO PARA LISTAR OS PROFESSORES COM MESTRADO.
                    ImprimeProfessorMestrado(DepartamentoBuscado);
                }
                else
                {
                    int i;
                    for(i = 5 ; i > 0 ; i--)
                    {
                        //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                        system("color 04");
                        printf("\n\t\tOPS, Não ha professores com mestrado .\n\t\t\tVoce sera redirecionado para o menu inicial em %i ",i);
                        Sleep(1000);
                        system("cls");
                    }
                    system("color 07");
                }
            }
            else
            {
                int i;
                for(i = 5 ; i > 0 ; i--)
                {
                    //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                    system("color 04");
                    printf("\n\t\tOPS, Ainda não a departamentos cadastrados .\n\t\t\tVoce sera redirecionado para o menu inicial em %i ",i);
                    Sleep(1000);
                    system("cls");
                }
                system("color 07");
            }

            system("cls");

            break;
        case OPCAO4 :

            system("cls");

            //ANIMAÇÃO CARREGANDO
            carregando();

            //FUNÇÃO PARA BUSCAR O PRIMEIRO DEPARTAMENTO.
            DepartamentoBuscado = BuscaPrimeiroDepartamento(a);

            if(DepartamentoBuscado != NULL)
            {
                //VERIFICA SE TEM ALGUM PROFESSOR COM DOUTORADO
                if(buscaInformacao(DepartamentoBuscado,"Doutorado"))
                {
                    printf("PROFESSORES COM DOUTORADO : \n\n");
                    //FUNÇÃO PARA LISTAR OS PROFESSORES COM DOUTORADO.
                    ImprimeProfessorDoutorado(DepartamentoBuscado);
                }
                else
                {
                    int i;
                    for(i = 5 ; i > 0 ; i--)
                    {
                        //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                        system("color 04");
                        printf("\n\t\tOPS, Não a professores com doutorado .\n\t\t\tVoce sera redirecionado para o menu inicial em %i ",i);
                        Sleep(1000);
                        system("cls");
                    }
                    system("color 07");
                }
            }
            else
            {
                int i;
                for(i = 5 ; i > 0 ; i--)
                {
                    //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                    system("color 04");
                    printf("\n\t\tOPS, Ainda não a departamentos cadastrados .\n\t\t\tVocê sera redirecionado para o menu inicial em %i ",i);
                    Sleep(1000);
                    system("cls");
                }
                system("color 07");
            }

            system("cls");

            break;
        case OPCAO5 :

            system("cls");

            //FUNÇÃO  QUE BUSCA O PRIMEIRO DEPARTAMENTO.
            DepartamentoBuscado = BuscaPrimeiroDepartamento(a);

            if(DepartamentoBuscado != NULL)
            {
                //FUNÇÃO PARA SALVAR OS DADOS NO ARQUIVO.
                SalvaDadosArquivo(DepartamentoBuscado);

                //ANIMACAO SALVANDO DADOS
                animacaoSalvandoD();
                salvar = 1;
            }
            else
            {
                int i;
                for(i = 5 ; i > 0 ; i--)
                {
                    //Onde a primeira letra é a cor do CMD e a segunda a do texto.
                    system("color 04");
                    printf("\n\t\tNão ha dados para serem salvos .\n\t\t\tVoçe sera redirecionado para o menu inicial em %i ",i);
                    Sleep(1000);
                    system("cls");
                }
                system("color 07");
            }

            system("cls");

            break;
        case OPCAO6 :

            system("cls");

            if(salvar != 0)
            {
                //OPC RECEBE 0 PARA FECHAR O PROGRAMA
                saida = 1;
                animacaoSaindo();
                //FUNÇÃO PARA LIBERAR A ESTRUTURA.
                LiberaEstrutura(a);
            }
            else
            {
                //MENU PERGUNTANDO SE DESEJA SALVAR OS DADOS.
                printf(" ___________________________________________________________\n");
                printf("|                                                           |\n");
                printf("|      Os dados não foram salvos no arquivo .               |\n");
                printf("|___________________________________________________________|\n");
                printf("|               |                                           |\n");
                ApresentaMenu(N_OPCAO_SUB,OPCAO6_SUB_OPCAO1,
                              TITULO_OPCAO6_SUB_OPCAO1,
                              TITULO_OPCAO6_SUB_OPCAO2);
                printf("|_______________|___________________________________________|\n");

                //LACO PARA DETALHES DO MENU NA LATERAL DIREITA
                int m;
                for(m = 6 ; m <= 7; m++)
                {
                    gotoxy(61,m);
                    printf("|");
                }

                op = LerOpcao(OPCAO6_SUB_OPCAO1,OPCAO6_SUB_OPCAO1 + N_OPCAO_SUB - 1);

                system("cls");

                if(op != OPCAO6_SUB_OPCAO2)
                {
                    //FUNÇÃO QUE BUSCA O PRIMEIRO DEPARTAMENTO
                    DepartamentoBuscado = BuscaPrimeiroDepartamento(a);

                    //FUNÇÃO PARA SALVAR PROFESSORES NO ARQUIVO
                    SalvaDadosArquivo(DepartamentoBuscado);

                    saida = 1;
                    animacaoSaindo();
                    //FUNÇÃO PARA LIBERAR A ESTRUTURA
                    LiberaEstrutura(a);
                }
                else
                {
                    animacaoSaindo();
                    saida = 1;
                    //FUNCAO PARA LIBERAR A ESTRUTURA.
                    LiberaEstrutura(a);
                }
            }

            system("cls");

            break;
        default:

            system("cls");

            //Onde a primeira letra é a cor do CMD e a segunda a do texto.
            system("color 04");
            printf("\t\tEste programa possui um bug .");
            system("color 07");
            return 1;

            system("cls");

            break;
        }
    }

    return 0;
}

