#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

//Que 1(b) Same Program Different Code
/* Same program with child and parent having different instructions/code. */
void main()
{
	int pid;
	pid = fork();

	if(pid<0)
	{
		 printf("Fork Failed\n");
	}
	else if(pid>0)
	{
		printf(" Hello, I am a Parent \n");
	}
	else
	{
		printf(" Hello, I am a child \n");
	}
}
