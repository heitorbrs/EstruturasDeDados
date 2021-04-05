#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

/****************************************************/

typedef struct svalor{
    char val[20];
}Valor;

/****************************************************/

typedef struct slista{
    Valor elem[TAM];
    int ultimo;
}Lista;

/****************************************************/

void inicializarLista(Lista *lista) {
    lista->ultimo = -1;
}

/****************************************************/

int listaCheia(Lista *lista) {

    if(lista->ultimo==(TAM-1)){
        return 1;
    }
    return 0;
}

/****************************************************/

int listaVazia(Lista *lista) {

    if(lista->ultimo==(-1)){
        return 1;
    }
    return 0;
}

/****************************************************/

int inserirFim(Lista *lista, Valor v1) {

    int i;

    if(listaCheia(lista)==1) {
        printf("\n  ERRO: Lista Cheia!\n\n");
        return 0;
    }

    else {

        lista->elem[lista->ultimo] = v1;
        lista->ultimo = (lista->ultimo + 1);

        printf("\n  Lista = { ");

        for(i=0; i<=lista->ultimo; i++){
            v1 = lista->elem[i-1];
            printf("%s ", v1.val);
        }
        printf("}\n\n");

        return 1;
    }
}

/****************************************************/

int modificarElemento(Lista *lista, int posicao, Valor temp, Valor v1) {

    int i;

    if(posicao < 0 || posicao > lista->ultimo) {
        printf("\nERRO: Posição inválida!\n");
        return 0;
    }

    lista->elem[posicao-1] = temp;

    printf("\n  Lista = { ");

        for(i=0; i<=lista->ultimo; i++){
            v1 = lista->elem[i-1];
            printf("%s ", v1.val);
        }
        printf("}\n\n");

    return 1;
}

/****************************************************/

int main() {

    int opcao=0, posicao;

    Lista lista;
    Valor v1;
    Valor temp;

    setlocale(LC_ALL,"");

    while(opcao!=6) {

        system("cls");
        printf("*-------------------------------------*\n");
        printf("|    MENU PRINCIPAL                   |\n");
        printf("*-------------------------------------*\n");
        printf("| 1. Inicializar Lista                |\n");
        printf("| 2. Verificar se a lista está cheia  |\n");
        printf("| 3. Verificar de a lista está vazia  |\n");
        printf("| 4. Inserir um elemento na lista     |\n");
        printf("| 5. Modificar um elemento na lista   |\n");
        printf("| 6. Sair do programa                 |\n");
        printf("*-------------------------------------*\n");
        printf("\n");
        printf("  Opção: ");
        scanf("%d", &opcao);

        if(opcao==1) {
            inicializarLista(&lista);
            printf("\n  Lista inicializada!\n\n");
            system("pause");
        }

        else if(opcao==2) {
            listaCheia(&lista);

            if(listaCheia(&lista)==1) {
                printf("\n  Lista cheia!\n\n");
            }
            if(listaCheia(&lista)==0) {
                printf("\n  Lista não está cheia!\n\n");
            }
            system("pause");
        }

        else if(opcao==3){
            listaVazia(&lista);

            if(listaVazia(&lista)==1) {
                printf("\n  Lista vazia!\n\n");
            }
            if(listaVazia(&lista)==0) {
                printf("\n  Lista não está vazia!\n\n");
            }
            system("pause");
        }

        else if(opcao==4){
            printf("\n  Digite o elemento: ");
            scanf("%s", v1.val);
            inserirFim(&lista, v1);
            system("pause");
        }

        else if(opcao==5){
            printf("\n  Digite a posição: ");
            scanf("%d", &posicao);

            printf("\n  Digite o novo elemento: ");
            scanf("%s", temp.val);

            modificarElemento(&lista, posicao, temp, v1);
            system("pause");
        }

        else if(opcao==6) {
            break;
        }

        else {
            printf("\n  Digite uma opção válida!\n\n");
            system("pause");
        }
    }
    return 0;
}
