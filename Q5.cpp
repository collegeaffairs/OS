/*
Q5. WAP TO COPY FILES USING SYSTEM CALLS(USING COPY FUNCTION.
Created by Ayush Jha


*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void copy(int s, int d)

{

        int c=0;

        char m[50];

        while((c=read(s, m, sizeof(m))) >0)

        {

                write(d, m, c);

        }

}

void main()

{

        char source[10];

        char destination[10];

        int s;

        int d;

        printf("Enter the name of the source file: ");

        scanf("%s", source);

        printf("Enter the name of the destination file: ");

        scanf("%d", destination);

        s=open(source, 0);

        if(s==-1)

        {

                d=creat(destination, 1);

        }

        copy(s, d);

        close(s);

        close(d);

}



/*

OUTPUT : (test result)



Enter the name of the source file 

file1.c

Enter th name of the destination file 

copy1.c



vi copy1.c

#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

void main()

{

        int pid;

        pid=fork();

        if(pid < 0)

        {

                fprintf(stderr,"fork failed");

                exit(-1);

        }

        else

        {

                printf("hello...my pid is %d \n",pid);

                exit(0);

        }

}



*/
