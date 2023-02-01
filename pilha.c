#include <stdio.h>
#include <stdlib.h>
//Structs
// Criação do no da lista
typedef struct no{
   int info;
   struct no* prox;
}No;

//Estrutura da pilha 
typedef struct pilha {
    No* topo;
}Pilha;

//Funçoes:
//Criando a pilha
Pilha* criar() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo == NULL;
    return p;
} 

//Função auxiliar para inserir no topo
No* inse_inici(No* list, int valor) {
    No* p = (No*) malloc(sizeof(No));
    p->info = valor;
    p->prox = list;
    return p;
}

//Função auxiliar para retirar do topo
No* reti_inic(No* list) {
    No* p = list->prox;
    free(list);
    return p;
}

//Reponsavel por adicianora um novo elemento na pilha
void push(Pilha* p, int valor){
    p->topo = inse_inici(p->topo, valor);
}

//Reponsavel por tirar um elemento da pilha
int pop(Pilha* p) {
    int valor;

    valor = p->topo->info;
    p->topo = reti_inic(p->topo);
    return valor;
}

// ver a lista está vazia
void empty(Pilha* p) {
    if (p->topo == NULL) {
        printf("pilha vaizia");
    }else{
        printf("Ainda tem valores na pilha");
    }
}

// Retorna o tamanho da pilha
int size(Pilha* p) {
  No* a = p->topo;
  int size = 0;
  while (a != NULL) {
    size++;
    a = a->prox;
  }
  return size;
  
}


// Mostra a pilha executando
void printar (Pilha* p) {
    No* i; 
    for (i= p->topo; i!=NULL; i=i->prox){
        printf("%d\n", i->info);
    }
}

int main() {
    Pilha* p;
    p = criar();
    int op, valor;

    while (op != 6) {
        printf("\nEscolha uma opcao abaixo: \n");
        printf("[1]- Empilha\n");
        printf("[2]- Mostra a pilha\n");
        printf("[3]- Desempilhar\n");
        printf("[4]- Verificar de estar vazia\n");
        printf("[5]- Tamanho da Pilha\n");
        printf("[6]- Sair do programa\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                printf("Qual valor deseja empilhar? ");
                scanf("%d", &valor);
                push(p, valor);
                break;
            case 2:
                printar(p);
                break;        
            case 3:
                pop(p);
                break;
            case 4:
                empty(p);
                break;
            case 5:
                printf("%d\n", size(p));
                break;
            case 6:
                printf("Saindo....");
                break;
            default:
            printf("Opcao invalida, por favor tente novamente :)");
                break;
        }
    }

    return 0;
}
