#include "fila1.h"
#include <semaphore.h>
#include <stdlib.h>
struct fila{
    sem_t semaforo;
    int quantidade,inicio,final;
    int buffer[maximo];
};
Fila * cria_fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->quantidade = 0;
    }
    return fi;
}



int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->quantidade == 0)
        return 1;
    else
        return 0;
}
int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->quantidade == maximo)
        return 1;
    else
        return 0;
}


int insere_Fila(Fila* fi, int numero){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->buffer[fi->final] = numero;
    fi->final = (fi->final+1)%maximo;
    fi->quantidade++;
    return 1;

}

int remove_Fila(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%maximo;
    fi->quantidade--;
    return 1;
}

int consulta_Fila(Fila* fi, int *numero){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    *numero = fi->buffer[fi->inicio];
    return 1;
}
void consumir(Fila *fila,int *numero){
  consulta_Fila(fila,numero);
  remove_Fila(fila);
}


int getQuantidade(Fila *fi){
    return fi->quantidade;
}
 void setQuantidade(Fila *fi,int numero){
     fi->quantidade=numero;
 }
 sem_t getSemafaro(Fila * fi ){
     return fi->semaforo;
 }


