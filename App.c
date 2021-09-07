#include <sys/types.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Fila/fila1.h"
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "./libs/ultils.h"



int main(int argc, char *argv[]){
pid_t p;
  int id=0;

/* 
  Crie todos os recursos compartilhados aqui: 
  Ex.: Shared Memories (Filas), Pipes e Semaforos.
  ...
  ...
*/


/* Criar os 7 Processos
   Para isso, o corpo do for(;;) abaixo executa 
   7 vezes a system call fork(). 
   Para que somente o processo Pai crie filhos, 
   cada filho sai (break) do for(;;) assim que retorna da fork.
   O valor da variavel "id" em cada processo indica o seu papel 
   no programa (processos P1 ate P7). 
*/

  for(id=1; id<=7; id++){
      p = fork();
      if ( p < 0 ){ printf("Erro no fork()\n"); exit(-1);}
      if ( p == 0 )
	   break;	  
  }
int i;
	key_t key=5678;
	
	void *shared_memory = (void *)0;
	int shmid;

	shmid = shmget(key,maximo,0666|IPC_CREAT);
	if ( shmid == -1 )
	{
		printf("shmget falhou\n");
		exit(-1);
	}
	
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 )
	{
		printf("shmat falhou\n");
		exit(-1);
	}
		
	printf("Memoria compartilhada no endereco=%p\n", shared_memory);

	shared_area_ptr = (Fila*) shared_memory;
        sem_t retornaSemafato=getSemafaro(shared_area_ptr);
	if ( sem_init((sem_t *) &retornaSemafato,1,1) != 0 )
        {
                printf("sem_init falhou\n");
                exit(-1);
        }
	setQuantidade(shared_area_ptr,0);

  
  
/* Abaixo programe o codigo de cada processo �separadamente
   diferenciando-os pelo valor da variavel id.
*/

  if ( id <= 3 ){

for(;;)
	{
        sem_t retornaSemafato=getSemafaro(shared_area_ptr);

		     em_wait((sem_t*)&retornaSemafato);
			if ( getQuantidade(shared_area_ptr)==0 )
			{
			     for(i=0;i<maximo;i++)
				   insere_Fila(shared_area_ptr,geraNumeroRandom());
                    setQuantidade(shared_area_ptr,i);
			     printf("Produziu %d bytes\n",i);
			}
		     sem_post((sem_t*)&retornaSemafato);
	}
  } 
  else 
  if ( id == 4 ){
    int pdp4 =getpid();
      
    if(getQuantidade(shared_area_ptr)==maximo){
        signal(SIGUSR1,p4Consummer);
    }
  }
  else 
  if ( id == 5 ){
    printf("Executa o codigo de P5\n");
  }
  else 
  if ( id == 6 ){
    printf("Executa o codigo de P6\n");
  }
  else 
  if ( id == 7 ){
    printf("Executa o codigo de P7\n");
  }
  else 
  if ( id == 8 ){
    printf("Executa o codigo do Processo Pai\n");
/*  Ele pode aguardar os demais processos ou simplesmente finalizar neste ponto. 
    Lembre-se, o termino do Pai antes dos processos filhos nao causa o termino dos
    processos filhos. 
*/    
  }
 exit(0); /* Executado por todos os processos ao finalizarem */
}
