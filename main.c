#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct no{

    int valor;
    struct no *proximo;

}No;


int anter(){

    int a = 0;

    printf("\nInforme valor anterior a ser inserido: ");
    scanf("%d",&a);
    printf("\n");

    return a;


}

int valor(){

    int x = 0;

    printf("\nInforme valor: ");
    scanf("%d",&x);
    printf("\n");

    return x;

}

void inserir_inicio(No **lista){

    No *novo = NULL;

    novo = malloc(sizeof(No));

    if(novo){

        novo->valor = valor();

        novo->proximo = *lista; //faz com q o nosso novo endereco aponte para o "primeiro valor" antigo

        *lista = novo;  //muda o antigo endereco do inicio para o novo
    }

    else{
        printf("\nErro ao alocar memoria!");
    }

}

void inserir_final(No **lista){

    No *novo;

    No *aux;

    novo = malloc(sizeof(No));

    if(novo){

        novo->valor = valor();
        novo->proximo = NULL;


        if(*lista != NULL){ //verifica se o conteudo de lista é null

            aux = *lista;

            while(aux->proximo != NULL){
                aux = aux->proximo;
            }

            aux->proximo = novo;

        }
        else{
            *lista = novo; //caso for sabemos q n aponta para nada logo lista vazia e recebe novo
        }

    }
    else{
        printf("\nErro ao alocar memoria");
    }

}


void inserir_meio(No **lista){ //inserir no meio de dois valores

    No *novo;

    No *aux;

    novo = malloc(sizeof(No));

    if(novo){

        novo->valor = valor();

        if(*lista == NULL){
            novo->proximo  = NULL;

            *lista = novo;
        }

        else{

            int ant = anter();

            aux = *lista;

            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;

            }

            novo->proximo = aux->proximo;

            aux->proximo = novo;

        }

    }
    else{
        printf("\nErro ao alocar memoria ");
    }


}

void inseir_ordenado(No **lista){

    No *novo;

    No *aux;

    novo = malloc(sizeof(No));

    if(novo){

        novo->valor = valor();
        novo->proximo = NULL;

        if(*lista == NULL){
            *lista = novo;
        }

        else if(novo->valor < (*lista)->valor){ //verifica se o valor é menor q o primeiro da lista

            novo->proximo = *lista;

            *lista = novo;

        }

        else{
            aux = *lista; //aq "penduramos" o nosso valor fazendo uma inserção semelhante a do meio

            while(aux->proximo && novo->valor > aux->proximo->valor){

                aux = aux->proximo; // maior q este mas menor q o proximo valor ou seja no meio entre os dois
            }

            novo->proximo = aux->proximo; //novo aponta para o valor maior

            aux->proximo = novo; //valor atual de aux aponta para este valor intermediario
        }

    }
    else{
        printf("\nErro ao alocar memoria ");
    }


}

No * remover(No **lista){

    No *lixo;
    No *aux;

    int num;

    if(*lista){
        printf("\nInforme numero a ser removido: ");
        scanf("%d",&num);

        if(num == (*lista)->valor){
         lixo = *lista;
        *lista = lixo->proximo;

                return lixo;
        }

        aux = *lista;

        while(aux->proximo->valor != num && aux->proximo){
            aux = aux->proximo;
        }

        if(aux->proximo){
        lixo = aux->proximo;

        aux->proximo = lixo->proximo;

        return lixo;
        }

    }
    else{
        printf("\nLista vazia! ");
        return NULL;
    }

}

No * buscar(No **lista){

    int num;
    No *aux;

    if(*lista){

        printf("\nInforme numero a ser encontrado: ");
        scanf("%d",&num);

        if(num == (*lista)->valor){
            return *lista;
        }
        else{
            aux = *lista;

            while(aux->valor != num && aux){
                aux = aux->proximo;
            }

            return aux;
        }


    }
    else{
        printf("\nLista vazia!");
        return NULL;
    }

}

void imprimir(No *lista){


    while(lista){

        printf("\nValor : %d \n",lista->valor);

        lista = lista->proximo;
    }

}


int main(){

    No *lista = NULL;
    No *lixo;
    No *resultado;

    int opcao;

    do{

        printf("\n1 inicio / 2 final / 3 meio / 4 ordenado / 5 imprimir  / 6 excluir / 7 buscar / 0 sair \n");
        printf("> ");
        scanf("%d",&opcao);

        switch(opcao){

        case 1: inserir_inicio(&lista); break;

        case 2: inserir_final(&lista); break;

        case 3: inserir_meio(&lista); break;

        case 4 : inseir_ordenado(&lista); break;

        case 5: imprimir(lista); break;

        case 6: lixo = remover(&lista); free(lixo);  break;

        case 7: resultado = buscar(&lista);

                printf("\nValor achado: %d ",resultado->valor);

                break;

        default:

            if(opcao != 0){

            printf("\nValor invalido ");

        }


        }


    }while(opcao != 0);

return 0;
}
