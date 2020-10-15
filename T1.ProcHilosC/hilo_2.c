#include <pthread.h>
#include <stdio.h>
void *codigo_del_hilo(void *id)       /* Itera el hilo 50  veces */
{
	int i;
	for(i = 0; i < 50; i++)
  	printf("\n Soy el hilo: %d, iter = %d", *(int*)id, i);    /* Hilo imprime descripción de la iteración*/
 	pthread_exit(id);
 }

int main (void)
{
	pthread_t hilo1, hilo2;  /* Inicializa e2 hilos*/
	int id1=11;              /* Numero ID de un hilo  */
	int id2=55;              /* Numero ID del otro hilo  */
	//int *salida;

	pthread_create(&hilo1, NULL, codigo_del_hilo, &id1); /* Crea el hilo 1 con la la iteración de codigo_del_hilo   */
  	pthread_create(&hilo2, NULL, codigo_del_hilo, &id2); /* Crea el hilo 2 con la la iteración de codigo_del_hilo   */

  	pthread_join(hilo1, NULL); /* En espera a la funcion del otro hilo  */
  	pthread_join(hilo2, NULL); /* En espera a la funcion del otro hilo  */

  	printf("\n Hilos terminados \n"); /* Termino de los hilos*/

  	return(0);
}
