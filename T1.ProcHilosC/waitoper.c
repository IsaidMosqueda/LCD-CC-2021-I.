#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
   int i;
   int a,b;
   pid_t pidh1,pidh2,pidx;
   int prod,mayor;
   int res;

   printf("\nDame dos enteros: \n"); /*  */
   scanf("%d%d", &a, &b);
   pidh1 = fork();

// código del padre
   if(pidh1) /* Si es padre crearemos otro hijo */
   {
      pidh2 = fork(); /* Si es padre crearemos otro hijo */
      if(pidh2) 
      {
        for(i = 0; i < 2; i++)
        {
           pidx = wait(&res); /*  Esperamos AL HIJO 2 */
 	   if (pidx == pidh1) 
             prod = res;            /* Ejecución del hijo para el prod y mayor */
           else
             mayor = res;
        }
        printf("\n El producto de %d y %d es %d", a,b,prod);
        printf("\n El mayor de %d y %d es %d \n", a,b,mayor);
      }

      else			/*  Termina aqui el hijo 2*/
      {
         if(a > b)
           exit(a);
         else
           exit(b);
      }				/* Y termina la ejecución del padre */
   }
// hijo 1
   else
      {				/* Si era hijo entonces, realizamos ep prod */
	 prod = a * b;
	 exit(prod);
      }

  return(0);

 }
