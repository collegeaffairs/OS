#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

//Que 1 (a) Same Program Same Code
/*Program to show pid of child and parent process*/
int main()
{
	int pid;
	pid= fork();
	
	printf("Hello, My pid is %d \n", pid);
	exit(-1);
}
