#include <pthread.h>
#include <stdio.h>


void *codigo_del_hilo(void *id)
{
 int i;          
 for(i = 0; i < 50; i++) /* Itera el hilo 50  veces */
  printf("\n Soy el hilo: %d, iter = %d", *(int*)id, i); /* Hilo imprime descripción de la iteración*/
 pthread_exit(id);
}

int main(void)
{
  pthread_t hilo; /* Inicializa el hilo */
  int id = 245; /* Numero ID del hilo  */
  int *salida;
  pthread_create(&hilo, NULL, codigo_del_hilo, &id); /* Crea el hilo con la la iteración de codigo_del_hilo   */
  pthread_join(hilo, NULL); /* En espera a la funcion del hilo  */
  printf("\n Hilo %d terminado \n", *salida); /* Termino del hilo*/
}
