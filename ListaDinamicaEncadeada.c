#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPessoa {
    char nome[50];
    int matricula;

} PESSOA;

/****************************************************/

typedef struct sCell {
    PESSOA info;
    struct sCell *next;

} CELULA;

/****************************************************/

CELULA* criarCelula() {
    CELULA *nova = (CELULA*)malloc(sizeof(CELULA));
    return nova;
}

/****************************************************/

void inicializarLista(CELULA **lista) {
    (*lista) = NULL;
}

/****************************************************/

int listaVazia(CELULA **lista) {
    if((*lista)==NULL){
        return 1;
    }
    return 0;
}

/****************************************************/

int inserirFim(CELULA **lista, PESSOA elemento) {
    CELULA *novaCelula;
    CELULA *auxiliar;

    novaCelula = criarCelula();

    if(novaCelula == NULL) {
        printf("\n  ERRO: Memoria cheia.\n\n");
        return 0;
    }
    novaCelula->info = elemento;
    novaCelula->next = NULL;

    if(listaVazia(lista)) {
        (*lista) = novaCelula;
        return 1;
    }

    auxiliar = (*lista);

    while(auxiliar->next!=NULL) {
        auxiliar = auxiliar->next;
    }
    auxiliar->next = novaCelula;
    return 1;

}

/****************************************************/

int inserirInicio(CELULA **lista, PESSOA elemento) {
    CELULA *novaCelula = criarCelula();

    if(novaCelula == NULL) {
        printf("\n  ERRO: Memoria Cheia!\n\n");
        return 0;
    }
    if(listaVazia(lista)) {
        return inserirFim(lista, elemento);
    }

    novaCelula->info = elemento;
    novaCelula->next = (*lista);
    (*lista) = novaCelula;

    return 1;
}

/****************************************************/

void imprimirLista(CELULA **lista, PESSOA elemento) {
    CELULA *auxiliar = (*lista);

    if(listaVazia(lista)) {
        printf("\n  Lista Vazia.\n");
    }
    else {
        printf("\n  Lista:\n");
        while(auxiliar!=NULL) {
            printf("\n  Matricula: %d | Nome: %s", auxiliar->info.matricula, auxiliar->info.nome);
            auxiliar = auxiliar->next;
        }
        printf("\n");
    }
}

/****************************************************/

PESSOA removerInicio(CELULA **lista) {

    CELULA *removida;

    PESSOA removido;
    strcpy(removido.nome, " ");
    removido.matricula = -1;

    if(listaVazia(lista)) {
        printf("\n  ERRO: Lista vazia!\n\n");
        return removido;
    }

    removida = (*lista);
    removido = removida->info;

    (*lista) = (*lista)->next;

    free(removida);
    return removido;
}

/****************************************************/

PESSOA removerFinal(CELULA **lista) {

    CELULA *removida;
    CELULA *anterior;
    PESSOA removido;

    if(listaVazia(lista)) {
        printf("\n  ERRO: Lista Vazia!\n\n");
        return removido;
    }

    if((*lista)->next == NULL) {
        return removerInicio(lista);
    }

    removida = (*lista);

    while(removida->next != NULL) {
        anterior = removida;
        removida = removida->next;
    }

    removido = removida->info;
    anterior->next = NULL;
    free(removida);
    return removido;
}

/****************************************************/

CELULA *pesquisarMatr(CELULA **lista, int mat) {
    CELULA *auxiliar;

    if(listaVazia(lista)) {
        printf("\n  Lista Vazia.\n");
        return NULL;
    }

    auxiliar = (*lista);
    while(auxiliar != NULL) {
        if(auxiliar->info.matricula == mat) {
            return auxiliar;
        }
        auxiliar = auxiliar->next;
    }
    return NULL;
}

/****************************************************/

PESSOA removerMatr(CELULA **lista, int mat) {

    CELULA *removida;
    CELULA *anterior;

    PESSOA p;

    if(listaVazia(lista)) {
        printf("  Lista Vazia.\n\n");
        return p;
    }

    removida = pesquisarMatr(lista, mat);

    if(removida == NULL) {
        printf("\n  ERRO: Matricula nao encontrada.\n\n");
        return p;
    }

    if(removida == (*lista)) {
        return removerInicio(lista);
    }

    p = removida->info;
    anterior = (*lista);

    while(anterior->next != removida) {
        anterior = anterior->next;
    }

    anterior->next = removida->next;

    free(removida);
    return p;
}

/****************************************************/

int main(){

    PESSOA temp;
    int opcao, matriculaTemp;
    char nomeTemp[50];
    CELULA *ptrlista, *tempCel;
    inicializarLista(&ptrlista);

    for(;;) {

        system("cls");
        printf("+-------------------------------------+\n");
        printf("|    CADASTRO DE ALUNO                |\n");
        printf("+-------------------------------------+\n");
        printf("| 1. Inicializar Lista                |\n");
        printf("| 2. Verificar se a lista esta vazia  |\n");
        printf("| 3. Inserir no inicio da lista       |\n");
        printf("| 4. Inserir no final da lista        |\n");
        printf("| 5. Remover no inicio da lista       |\n");
        printf("| 6. Remover no final da lista        |\n");
        printf("| 7. Imprimir lista                   |\n");
        printf("| 8. Pesquisar pela matricula         |\n");
        printf("| 9. Remover pela matricula           |\n");
        printf("| 0. Sair do programa                 |\n");
        printf("+-------------------------------------+\n");
        printf("\n  Escolha uma opcao\n");
        printf("\n  >>> ");
        scanf("%d", &opcao);

        //inicializar lista
        if(opcao==1) {
            inicializarLista(&ptrlista);
            printf("\n  Lista inicializada!\n\n");
            system("pause");
        }

        //verificar se a lista está vazia
        else if(opcao==2) {
            listaVazia(&ptrlista);
            if(listaVazia(&ptrlista)==1) {
                printf("\n  Lista Vazia\n\n");
            }
            if(listaVazia(&ptrlista)==0) {
                printf("\n  Lista nao Vazia\n\n");
            }
            system("pause");
        }

        //inserir no inicio da lista
        else if(opcao==3) {
            printf("\n  Nome: ");
            scanf(" %[^\n]", nomeTemp);
            strcpy(temp.nome, nomeTemp);

            printf("\n  Matricula: ");
            scanf("%d", &temp.matricula);

            inserirInicio(&ptrlista, temp);
            printf("\n");
            system("pause");
        }

        //inserir no final da lista
        else if(opcao==4) {
            printf("\n  Nome: ");
            scanf(" %[^\n]", nomeTemp);
            strcpy(temp.nome, nomeTemp);

            printf("\n  Matricula: ");
            scanf("%d", &temp.matricula);

            inserirFim(&ptrlista, temp);
            printf("\n");
            system("pause");
        }

        //remover no inicio da lista
        else if(opcao==5) {
            removerInicio(&ptrlista);
            printf("\n  REMOVIDO COM SUCESSO!\n\n");
            system("pause");
        }

        //remover no final da lista
        else if(opcao==6) {
            removerFinal(&ptrlista);
            printf("\n  REMOVIDO COM SUCESSO!\n\n");
            system("pause");
        }

        else if(opcao==7) {
            imprimirLista(&ptrlista, temp);
            printf("\n");
            system("pause");
        }

        //pesquisar pela matricula
        else if(opcao==8) {
            printf("\n  Digite a matricula: ");
            scanf("%d", &matriculaTemp);

            tempCel = pesquisarMatr(&ptrlista, matriculaTemp);

            if (tempCel != NULL) {
                printf("\n  Encontrada\n\n");
            }
            else {
                printf("\n  Nao encontrada\n\n");
            }
            system("pause");
        }

        //remover pela matricula
        else if(opcao==9) {
            printf("\n  Digite a matricula: ");
            scanf("%d", &matriculaTemp);

            temp = removerMatr(&ptrlista, matriculaTemp);

            printf("\n  REMOVIDO COM SUCESSO!\n\n");
            system("pause");
        }

        //sair do programa
        else if(opcao==0) {
            break;
        }

        else {
            printf("\n  Digite uma opcao valida!\n\n");
            system("pause");
        }
    }

    return 0;
}

