#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  pid_t pid;
  int status, died;

  switch(pid = fork()) {

    case -1: printf(" No es posible hacer el fork...\n");
             exit(-1);

    // codigo que ejecuta el hijo
    case 0: printf("\tCódigo del hijo...\n" );
            //sleep(10);
            int i=1;
            while (i<=10){
              printf("\t\t Tarea del proceso hijo: %d\n", i++);
              sleep (1);
            }
            //break;
            exit(1);

    // codigo que ejecuta el padre
    default: printf("Código que ejecuta el padre\n" );
             died = wait(&status);
             printf("Terminó el proceso hijo: %d \n", died);
    }

    return(0);
}