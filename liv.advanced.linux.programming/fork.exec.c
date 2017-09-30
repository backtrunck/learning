#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spaw(char *program, char **arg_list){
	pid_t child_id;

	/*Duplicar o processo*/
	child_pid = fork();

	if(child_pid != 0)
		return child_pid;
	else{
		execvp(program, arg_list);
		fprintf(stderr,"Um erro ocorreu em execvp\n");
		abort();
	}	
}

int main(){
	char *arg_list[] = {
		"ls",
		"-l",
		"/",
		NULL};
	spawn("ls", arg_list);
	printf("Programa Principal executado");

	return 0;
}