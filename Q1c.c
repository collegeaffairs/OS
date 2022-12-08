
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

//Que 1(c)
/*Before terminating, parent waits for child to finish its task.*/
void main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)
	{
		printf("Process Failed");
	}
	else if(pid==0)
	{
		printf("Child Process\n");
	}
	else
	{
		wait(NULL);
		printf("Parent Process\n");
	}
	return;
}



