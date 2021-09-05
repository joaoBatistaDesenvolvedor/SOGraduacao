#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Fila/fila1.h"
#include <unistd.h>
#include <signal.h>
#include <time.h>
int geraNumeroRandom(){
      srand(time(NULL));
        return 1+(rand()%1000);
}
void p4Consummer(int sig,Fila *shared_area_ptr){
    int i;
    int valorConsumido;
      	for(;;)
	{
        sem_t retornaOsemaforo=getSemafaro(shared_area_ptr);
            
			sem_wait((sem_t*)&retornaOsemaforo);
			     if ( getQuantidade(shared_area_ptr)> 0 )
			     {	
			         for(i=0;i<getQuantidade(shared_area_ptr);i++)
                        consumir(shared_area_ptr,&valorConsumido);
			                printf("%d",valorConsumido);
                            setQuantidade(shared_area_ptr,0);
				 printf("\nConsumiu %d bytes\n",i); 
			      }	
			sem_post((sem_t*)&retornaOsemaforo);
		
	}

}