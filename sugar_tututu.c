#include <stdio.h> //standard input/output
#include <pthread.h> //para usar threads

#include <unistd.h>     // para hacer sleep
#include <stdlib.h>     // para libreria de numeros random: srand, rand 
#include <time.h>       // para tomar el tiempo 
#include <semaphore.h>

#define NUM_THREADS 4
sem_t semaphore1, semaphore2, semaphore3, semaphore4;
char signal;
int loopTrigger = 1;

//cada funcion tocar_movimiento_i toca una parte de la melodia
void* tocar_movimiento_1 (void* parametro)
{
	
	system("echo Start; mplayer -really-quiet part1_SugarSugar.mp3");
	sem_post(&semaphore1);   
   	pthread_exit(NULL);
   
}

void* tocar_movimiento_2 (void* parametro)
{   

	sem_wait(&semaphore1);
	system("mplayer -really-quiet part2_SugarSugar.mp3");
	sem_post(&semaphore2);   
   	pthread_exit(NULL);
   
}

void* tocar_movimiento_3 (void* parametro)
{   
	
	sem_wait(&semaphore2);
	system("mplayer -really-quiet part3_SugarSugar.mp3");
	sem_post(&semaphore3);   
   	pthread_exit(NULL);
   
}

void* tocar_movimiento_4 (void* parametro)
{   
	
	sem_wait(&semaphore3);
	system("mplayer -really-quiet part4_SugarSugar.mp3");
	sem_post(&semaphore4);
	pthread_exit(NULL);
   
}

int main ()
{
   
   	pthread_t threads[NUM_THREADS]; //una variable de tipo pthread_t sirve para identificar cada hilo que se cree
                                   //la variable threads es una array de pthread_t
                                   //comparar con char data[100], un array de char                                           
	

	//genero los threads y los lanzo, observar que sin semaforos se ejecutan los 4 casi al mismo tiempo
	//y no se reconoce la melodía
	   	
	int rc;
   	rc = pthread_create(&threads[1], NULL, tocar_movimiento_2, NULL );
   	rc = pthread_create(&threads[0], NULL, tocar_movimiento_1, NULL );
   	rc = pthread_create(&threads[3], NULL, tocar_movimiento_4, NULL );
   	rc = pthread_create(&threads[2], NULL, tocar_movimiento_3, NULL );
   	

	//esperar a que los threads terminen para terminar el programa principal
	int i;
    	for(i = 0 ; i < NUM_THREADS ; i++)
    	{
        	pthread_join(threads[i] , NULL);
    	}

	
	
	pthread_exit(NULL);
	return EXIT_SUCCESS;
}

//Para compilar:   gcc sugar_tututu.c -o sugar_tututu -lpthread
//Para ejecutar:   ./sugar_tututu






