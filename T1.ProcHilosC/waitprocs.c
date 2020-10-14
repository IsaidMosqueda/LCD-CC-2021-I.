#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

# define NUM_PROCESOS 5
int I = 0;

void codigo_del_proceso (int id)     /*Proceso que imprime la información del proceso llamado */
{
   int i;

   for (i = 0; i < 50; i++)
        printf("Proceso %d: i = %d, I = %d\n", id, i, I++ );
   exit (id);

}

int main(void)
{
    int p;
    int id[NUM_PROCESOS] = {1, 2, 3, 4, 5}; /*Crea una lista de ids para los procesos*/
    int pid;
    int salida;

    for (p = 0; p < NUM_PROCESOS; p++) {  /* codigo proceso hijo */
      pid = fork();
      if  (pid == -1){                              /* Cuando el proceso hijo es -1 se detiene el proceso*/
          perror("Error al crear un proceso: ");
          exit(-1);
      }
      else if (pid == 0) /* codigo proceso hijo */
          codigo_del_proceso (id[p]);            /* El proceso hijo es imprimir su identificador*/
    }

    // codigo proceso padre
    for (p = 0; p < NUM_PROCESOS; p++) {
        pid = wait(&salida);     /* Proceso padre espera a que termine el proceso hijo*/
        printf("Proceso %d con id = %x terminado\n", pid, salida >> 8);   /* Proceso padre imrpime la finalización del proceso hijo*/
    }

    return(0);
}
