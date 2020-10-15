#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_HILOS 5
int I = 0;

void *codigo_del_hilo(void *id)  /* Función que se empleará en los hilos, además incluye la variable compartida I como contador de iteraciones*/
{
    int i;
    for(i = 0; i < 50; i++)
      printf("Hilo %d; i = %d, I = %d\n", *(int*)id, i, I++);
 pthread_exit(id);
}

int main(void)
{
    int h;                        /*Inicializamos las varibales que oucparemos*/
    pthread_t hilos[NUM_HILOS];
    int id[NUM_HILOS] = {1, 2, 3, 4, 5}; /*Creamos lista de id de cada hilo*/
    int error;
    int *salida;    

    for (h = 0; h < NUM_HILOS; h++){                /*Consideramos el caso de error*/
        error = pthread_create(&hilos[h], NULL, codigo_del_hilo, &id[h]);
        if (error){
          fprintf(stderr, "Error %d %s\n", error, strerror (error));
          exit(-1);
        }
    }    

    for (h = 0; h < NUM_HILOS; h++){    /*Creamos todos los hilos que son referenciados en los valores de la lista de ids*/
        error = pthread_join(hilos[h], (void **)&salida);
        if (error)
          fprintf(stderr, "Error %d %s\n", error, strerror (error));
        else
          printf("hilo %d terminado\n", *salida);    
  }
}