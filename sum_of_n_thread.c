// Created by Ayush Jha
// Add the numbers using thread function


#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



int sum ;

void *runner (void *param)
{
	int i, upper = atoi(param);
	sum = 0;
	
	for (i = 1 ; i <= upper; i++)
	{
		sum+=i;
	}

	pthread_exit(0);
}

int main()
{
	pthread_t tid ;
	pthread_attr_t attr ;
	
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner,"100" );
	pthread_join(tid, NULL);
	
	printf("sum = %d\n", sum);
}


// int global[2];

// void *sum_thread(void *arg)
// {
//     int *args_array;
//     args_array = *(int**)arg;

//     int n1,n2,sum;
//     n1=args_array[0];
//     n2=args_array[1];
//     sum = n1+n2;

//     printf("N1 + N2 = %d\n",sum);

//     return NULL;
// }

// int main() 
// {
//     printf("First number: ");
//     scanf("%d",&global[0]);

//     printf("Second number: ");
//     scanf("%d",&global[1]);

//     pthread_t tid_sum;
//     pthread_create(&tid_sum,NULL,sum_thread,(void*)&global);
//     pthread_join(tid_sum,NULL);

//     return 0;
// }
