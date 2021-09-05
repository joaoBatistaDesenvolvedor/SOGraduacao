#define maximo 3
#include <semaphore.h>

typedef struct fila Fila;

Fila * cria_fila();
int Fila_vazia(Fila*);
int Fila_cheia(Fila*);
int insere_Fila(Fila*,int);
void consumir(Fila *,int *);
int getQuantidade(Fila *);
 void setQuantidade(Fila *, int);
 sem_t getSemafaro(Fila *);
