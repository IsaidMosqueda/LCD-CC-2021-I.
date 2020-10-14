#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(void){
	
	int 	fd[2], nbytes;
	pid_t	childpid;
	char	cadena[] = "Hola, mundo!!\n";
	char	lectura[80];

	pipe(fd);

	if ((childpid = fork()) == -1){
		perror("fork");
		exit(1);

	}

	if (childpid == 0){

		/* Proceso hijo cierra el pipe en el canal de entrada */
		close(fd[0]);

		/* Envía "cadena" por medio del canal de salida del pipe */
		write(fd[1], cadena, strlen(cadena));
		exit(0);
	}
	else{
		
		/* Proceso padre cierra el canal de salida del pipe */
		close(fd[1]);
		/* Lee "cadenacar" del pipe */
		nbytes = read(fd[0], lectura, sizeof(lectura));
		printf("Cadena recibida: %s", lectura);
	}

	return(0);


}