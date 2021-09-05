#include <stdio.h>
#include "./Fila/fila1.h"

int main(int argc, char **argv){

Fila *fila=cria_fila();
int numero;

insere_Fila(fila,1);
insere_Fila(fila,2);
insere_Fila(fila,3);
if(Fila_cheia(fila)){
  printf("fila cheia\n");
}
for (int i = 0; i < 3; i++)
{
  consumir(fila,&numero);
  printf("valor na fila %d\n",numero);
}


if(Fila_vazia(fila)){
  printf("nao tenho o que consumir ");
}





}
