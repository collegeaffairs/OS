/*

Q4. WAP TO PRINT FILE DETAILS INCLUDING OWNER ACCESS PERMISSIONS, FILE ACCESS TIME WHERE FILE NAME IS GIVEN AS ARGUMENT.
Created by Ayush Jha

*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void main(int argc,char *argv[])

{

	struct stat statbuf;

	int fd;

	if(argc!=2)
	{

		printf("Wrong no. of arguements");

		exit(0);

	}

	fd=open(argv[1],0,0744);

	if(fd==-1)
	{

		printf("File not opened");

		exit(0);

	}

	fstat(fd,&statbuf);

	close(fd);

	printf("Owner uid=%d\n",statbuf.st_uid);

	printf("Group id=%d\n",statbuf.st_gid);

	printf("Access Permission=%d\n",statbuf.st_mode);

	printf("Size=%d\n",statbuf.st_size);

	printf("No. of links=%d\n",statbuf.st_nlink);

	printf("Last access time= %s\n", ctime(&statbuf.st_atime));

	printf("Last modified time= %s\n",ctime(&statbuf.st_mtime));

}



/*

OUTPUT



owner uid = 0

group id = 13

access permissions = 33216

size = 231

number of links = 1

last access time = Tue Apr 03 14:18:21 2001



last modification time = Mon Jan 16 14:05:05 1995

*/
