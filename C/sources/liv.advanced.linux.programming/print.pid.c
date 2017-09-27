#include <stdio.h>
#include <unistd.h>

int main(){
	printf("The Process ID is %d\n",getpid());
	printf("The Parent Process ID is %d",getpid());
	return 0;
}