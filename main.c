#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "apresentacao.h"
#define MAX 10

/*
Diogo Vitor Oliveira Leme
RA: 836846
Engenharia de Software - UNAERP RP
*/

struct cadastro{
        char nome[50];
        char autor[50];
        char ISBN[50];
        char qtdPg[50];
        char editora[50];
        char ano[50];
        char preco[50];
};

//Variáveis GLOBAIS
char Linha[100];
char *resultado;
int i = 0;
struct cadastro livros[MAX];
FILE *arquivo;
//

void c_prioridade(){//REGISTRAR COM prioridade
    int j = 0, q, resposta;

    /* USO DE WHILE

    q = i;
    while(q >= 0){
        strcpy(livros[q+1].nome, livros[q].nome);
        strcpy(livros[q+1].autor, livros[q].autor);
        livros[q+1].ISBN = livros[q].ISBN;
        livros[q+1].qtdPg = livros[q].qtdPg;
        strcpy(livros[q+1].editora, livros[q].editora);
        livros[q+1].ano = livros[q].ano;
        livros[q+1].preco = livros[q].preco;
        q --;
    } */

    if(i < 10){

    for(q = i; q >= 0; q --){
        strcpy(livros[q+1].nome, livros[q].nome);
        strcpy(livros[q+1].autor, livros[q].autor);
        strcpy(livros[q+1].ISBN, livros[q].ISBN);
        strcpy(livros[q+1].qtdPg, livros[q].qtdPg);
        strcpy(livros[q+1].editora, livros[q].editora);
        strcpy(livros[q+1].ano, livros[q].ano);
        strcpy(livros[q+1].preco, livros[q].preco);
    }

    printf("\n\tREGISTRO DE LIVROS com prioridade\n");

    printf("\nRegistro N 1");
    printf("\nNOME: ");
    fflush(stdin);
    gets(livros[0].nome);

    printf("AUTOR: ");
    fflush(stdin);
    gets(livros[0].autor);

    printf("ISBN: ");
    fflush(stdin);
    gets(livros[0].ISBN);

    printf("QTD DE PAGS: ");
    fflush(stdin);
    gets(livros[0].qtdPg);

    printf("EDITORA: ");
    fflush(stdin);
    gets(livros[0].editora);

    printf("ANO: ");
    fflush(stdin);
    gets(livros[0].ano);

    printf("PRECO: ");
    fflush(stdin);
    gets(livros[0].preco);

    i++;

    }else{
        printf("\nLimite de registros atingido.\n");
        printf("Para continuar, exclua outros registros e retorne.\n\n");
        outraAtv(livros);
    }
    outraAtv(livros);
}//REGISTRAR COM prioridade

void s_prioridade(){//Exibir SEM prioridade
    int resposta1, resposta2 = 2;

    printf("\n\tREGISTRO DE LIVROS sem prioridade\n");
        while(resposta2 == 2){
            if(i < 10){
                if (i == 0){
                    arquivo = fopen("Livros Registrados.txt", "w");
                }else {
                    arquivo = fopen("Livros Registrados.txt", "a");
                }

                if(arquivo == NULL){
                  printf("Erro na abertura do arquivo!");
                  exit(0);
                }

            printf("\nRegistro %i", i+1);
            fprintf(arquivo, "Registro %i\n", i+1);
            printf("\nNOME: ");
            fflush(stdin);
            gets(livros[i].nome);
            fprintf(arquivo, "NOME: %s\n", livros[i].nome);

            printf("AUTOR: ");
            fflush(stdin);
            gets(livros[i].autor);
            fprintf(arquivo, "AUTOR: %s\n", livros[i].autor);

            printf("ISBN: ");
            fflush(stdin);
            gets(livros[i].ISBN);
            fprintf(arquivo, "ISBN: %s\n", livros[i].ISBN);

            printf("QTD DE PAGS: ");
            fflush(stdin);
            gets(livros[i].qtdPg);
            fprintf(arquivo, "QTD DE PAGS: %s\n", livros[i].qtdPg);

            printf("EDITORA: ");
            fflush(stdin);
            gets(livros[i].editora);
            fprintf(arquivo, "EDITORA: %s\n", livros[i].editora);

            printf("ANO: ");
            fflush(stdin);
            gets(livros[i].ano);
            fprintf(arquivo, "ANO: %s\n", livros[i].ano);

            printf("PRECO: ");
            fflush(stdin);
            gets(livros[i].preco);
            fprintf(arquivo, "PRECO: %s\n", livros[i].preco);
            fprintf(arquivo, "-\n");

            i++;

            fclose(arquivo);

            printf("\nContinuar o registro?\n");
            printf("Sim [1] - Nao [2]: ");
            scanf("%i", &resposta1);
                if(resposta1 != 1){
                    printf("TEM CERTEZA?\n");
                    printf("Sim [1] - Nao [2]: ");
                    scanf("%i", &resposta2);
                    }
                }else{
                    printf("\nLimite de registros atingido.\n");
                    printf("Para continuar, exclua outros registros e retorne.\n\n");
                    break;
                }
        }
        menu(livros);
}//REGISTRAR SEM prioridade

void exibir(){//EXIBIR
    int opcao, resposta, escolha;
    int j = 0;
    char nome_autor[50], nome_editora[50], ano[50];
    int x;
    //int ano;

    printf("\t[1] > Exibir registros \n");
    printf("\t[2] > Pesquisar livro por AUTOR \n");
    printf("\t[3] > Pesquisar livro por EDITORA \n");
    printf("\t[4] > Exibir livros conforme seu ANO \n");
    printf("Opcao: ");
    scanf("%i", &opcao);

    //switch(opcao){

    if(opcao == 1){ // Exibir Resgistros
        j = 0;

        printf("Exibir registros...\n");
        printf("1 > Arquivo .txt\n");
        printf("2 > Registros gerais\n");
        printf("Decisao: ");
        scanf("%i", &escolha);
        printf("\n");

        if(escolha == 1){//Exibição do arquivo .txt
            printf("\n\tEXIBICAO DE REGISTROS .txt\n");
            arquivo = fopen("Livros Registrados.txt", "r");

            if (arquivo == NULL){ // Se houver erro na abertura
                 printf("Problemas na abertura do arquivo\n");
                 exit(0);
            }
            x = 1;
            while (!feof(arquivo)){
                resultado = fgets(Linha, 1000, arquivo);
                    if (resultado){
                        printf("%s", Linha);
                    }
            }
            fclose(arquivo);
            outraAtv(livros);
        }

        else if(escolha == 2){//Exibição dos registros no cmd
            printf("\n\tEXIBICAO DE REGISTROS\n");
            while(j < i){
                printf("\n\tRegistro %i", j+1);
                printf("\nNOME: %s", livros[j].nome);
                printf("\nAUTOR(A): %s", livros[j].autor);
                printf("\nISBN: %s", livros[j].ISBN);
                printf("\nQTD DE PAGS: %s", livros[j].qtdPg);
                printf("\nEDITORA: %s", livros[j].editora);
                printf("\nANO: %s", livros[j].ano);
                printf("\nPRECO: R$%s\n", livros[j].preco);

                j++;
            }
            outraAtv(livros);
        }
// Exibir Resgistros
    }
    j = 0;

    if(opcao == 2){ // Pesquisar AUTOR
        FILE *arq_autor;
        arq_autor = fopen("Filtragem AUTOR.txt", "w");

        j = 0;
        printf("\n\tPESQUISAR REGISTRO PELO AUTOR(A)\n");
        printf("Digite o nome do autor: ");
        fflush(stdin);
        gets(nome_autor);
        while(j < i){
            if(strcmp(nome_autor, livros[j].autor) == 0){
                printf("\n\tRegistro %i", j+1);
                    fprintf(arq_autor, "Registro %i\n", j+1);
                printf("\nNOME: %s", livros[j].nome);
                    fprintf(arq_autor, "NOME: %s\n", livros[j].nome);
                printf("\nAUTOR(A): %s", livros[j].autor);
                    fprintf(arq_autor, "AUTOR(A): %s\n", livros[j].autor);
                printf("\nISBN: %s", livros[j].ISBN);
                    fprintf(arq_autor, "ISBN: %s\n", livros[j].ISBN);
                printf("\nQTD DE PAGS: %s", livros[j].qtdPg);
                    fprintf(arq_autor, "QTD DE PAGS: %s\n", livros[j].qtdPg);
                printf("\nEDITORA: %s", livros[j].editora);
                    fprintf(arq_autor, "EDITORA: %s\n", livros[j].editora);
                printf("\nANO: %s", livros[j].ano);
                    fprintf(arq_autor, "ANO: %s\n", livros[j].ano);
                printf("\nPRECO: R$%s\n", livros[j].preco);
                    fprintf(arq_autor, "PRECO: %s\n", livros[j].preco);
                    fprintf(arq_autor, "-\n");
            }

            j++;
        }

        fclose(arq_autor);
        outraAtv(livros);
    }
// Pesquisar AUTOR
j = 0;

    if(opcao == 3){ // Pesquisar EDITORA
        FILE *arq_editora;
        arq_editora = fopen("Filtragem EDITORA.txt", "w");

        j = 0;
        printf("\n\tPESQUISAR REGISTRO PELA EDITORA\n");
        printf("Digite o nome da editora: ");
        fflush(stdin);
        gets(nome_editora);
        while(j < i){
            if(strcmp(nome_editora, livros[j].editora) == 0){
                printf("\n\tRegistro %i", j+1);
                    fprintf(arq_editora, "Registro %i\n", j+1);
                printf("\nNOME: %s", livros[j].nome);
                    fprintf(arq_editora, "NOME: %s\n", livros[j].nome);
                printf("\nAUTOR(A): %s", livros[j].autor);
                    fprintf(arq_editora, "AUTOR(A): %s\n", livros[j].autor);
                printf("\nISBN: %s", livros[j].ISBN);
                    fprintf(arq_editora, "ISBN: %s\n", livros[j].ISBN);
                printf("\nQTD DE PAGS: %s", livros[j].qtdPg);
                    fprintf(arq_editora, "QTD DE PAGS: %s\n", livros[j].qtdPg);
                printf("\nEDITORA: %s", livros[j].editora);
                    fprintf(arq_editora, "EDITORA: %s\n", livros[j].editora);
                printf("\nANO: %s", livros[j].ano);
                    fprintf(arq_editora, "ANO: %s\n", livros[j].ano);
                printf("\nPRECO: R$%s\n", livros[j].preco);
                    fprintf(arq_editora, "PRECO: R$%s\n", livros[j].preco);
                    fprintf(arq_editora, "-\n");
            }

            j++;
        }

        fclose(arq_editora);
        outraAtv(livros);
    }
// Pesquisar EDITORA
j = 0;

    if(opcao == 4){ // Pesquisar ANO
        FILE *arq_ano;
        arq_ano = fopen("Filtragem ANO.txt", "w");

        j = 0;
        printf("\n\tPESQUISAR REGISTRO PELO ANO\n");
        printf("Digite o ano de publicacao: ");
        fflush(stdin);
        gets(ano);
        while(j < i){
            if(strcmp(ano, livros[j].ano) == 0){
            //if(ano == livros[j].ano){
                printf("\n\tRegistro %i", j+1);
                    fprintf(arq_ano, "Registro %i\n", j+1);
                printf("\nNOME: %s", livros[j].nome);
                    fprintf(arq_ano, "NOME: %s\n", livros[j].nome);
                printf("\nAUTOR(A): %s", livros[j].autor);
                    fprintf(arq_ano, "AUTOR(A): %s\n", livros[j].autor);
                printf("\nISBN: %s", livros[j].ISBN);
                    fprintf(arq_ano, "ISBN: %s\n", livros[j].ISBN);
                printf("\nQTD DE PAGS: %s", livros[j].qtdPg);
                    fprintf(arq_ano, "QTD DE PAGS: %s\n", livros[j].qtdPg);
                printf("\nEDITORA: %s", livros[j].editora);
                    fprintf(arq_ano, "EDITORA: %s\n", livros[j].editora);
                printf("\nANO: %s", livros[j].ano);
                    fprintf(arq_ano, "ANO: %s\n", livros[j].ano);
                printf("\nPRECO: R$%s\n", livros[j].preco);
                    fprintf(arq_ano, "PRECO: R$%s\n", livros[j].preco);
                    fprintf(arq_ano, "-\n");

            }
            j++;
        }

        fclose(arq_ano);
        outraAtv(livros);
    }
// Pesquisar ANO
j = 0;
    }//EXIBIR

void excluir(){//EXCLUIR registros
    int j = 0, resposta;
    char nome_livro[50];

    printf("\n\tEXCLUIR REGISTRO\n");
    exibe_registro();
    printf("\nDigite o nome do Livro: ");
    fflush(stdin);
    gets(nome_livro);
        while (j < i){
            if(strcmp(nome_livro, livros[j].nome) == 0){
                printf("\n\tLivro %i \n", j+1);
                while (j < i){
                    strcpy(livros[j].nome, livros[j+1].nome);
                    strcpy(livros[j].autor, livros[j+1].autor);
                    strcpy(livros[j].ISBN, livros[j+1].ISBN);
                    strcpy(livros[j].qtdPg, livros[j+1].qtdPg);
                    strcpy(livros[j].editora, livros[j+1].editora);
                    strcpy(livros[j].ano, livros[j+1].ano);
                    strcpy(livros[j].preco, livros[j+1].preco);
                    j++;
                }
            }

            j++;
        }

        livros[i].nome[0] = NULL;
        livros[i].autor[0] =  NULL;
        livros[i].ISBN[0] = NULL;
        livros[i].qtdPg[0] = NULL;
        livros[i].editora[0] = NULL;
        livros[i].ano[0] = NULL;
        livros[i].preco[0] = NULL;

        i--;

        outraAtv(livros);
}//EXCLUIR registros

void outraAtv(){//Realizar OUTRA atividade
    int opcao;

    printf("\nRealizar outra atividade?\n");
        printf("1 > SIM\n");
        printf("0 > NAO\n");
        printf("Resposta: ");
            scanf("%i", &opcao);
                if(opcao == 1){
                    menu(livros);
                }else{
                    sair(livros);
                }
}//outraAtv

void exibe_registro(){
    int j = 0;

    while(j < i){
        printf("\n\tLivro %i", j+1);
        printf("\nNOME: %s", livros[j].nome);
        printf("\nAUTOR(A): %s", livros[j].autor);
        printf("\nISBN: %s", livros[j].ISBN);
        printf("\nQTD DE PAGS: %s", livros[j].qtdPg);
        printf("\nEDITORA: %s", livros[j].editora);
        printf("\nANO: %s", livros[j].ano);
        printf("\nPRECO: R$%s\n", livros[j].preco);

        j++;
    }

}//exibe_registro

void sair(){//SAIR
    printf("\n\tObrigado.\n");
    apresenta();//Função vinculada a biblioteca
    system("pause");
    system("exit");
}
//SAIR

void menu(){
    int opcao;

    system("cls");
        printf("Livraria 'O Escriba'\n");
        printf("--------------------\n");
        printf("[1] > Inserir Livro COM PRIORIDADE \n");
        printf("[2] > Inserir Livro SEM PRIORIDADE \n");
        printf("[3] > Exibir informacoes \n");
        printf("[4] > Excluir registro \n");
        printf("                          [0] > Sair \n");
        printf("Opcao: ");
        scanf("%i", &opcao);

        if(opcao < 0 || opcao > 5){
            printf("\nOpcao invalida.\n");
            menu(livros);
        }
        if(opcao == 1){c_prioridade(livros);}
        if(opcao == 2){s_prioridade(livros);}
        if(opcao == 3){exibir(livros);}
        if(opcao == 4){excluir(livros);}
        if(opcao == 0){sair(livros);}

}//menu

int main()
{
    menu(livros);
}//main
