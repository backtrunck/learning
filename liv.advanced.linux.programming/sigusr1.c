#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0 ;
void handler (int signal_number){
	++sigusr1_count =0;
}


int main(){
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	
	/*Do some lenghty stuff here */

	printf("SIGURS1 foi enviado %d vezes\n",sigusr1_count);
	return 0;
}