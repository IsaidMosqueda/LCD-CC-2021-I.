#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	
	int pid;
	pid = fork();
	
	printf("ID del proceso: %d\n", pid);

	if (pid == 0)
		printf("Proceso hijo \n");
	else
		printf("Proceso padre \n");

	return(0);

}