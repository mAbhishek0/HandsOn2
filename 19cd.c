/*
============================================================================
Name : 19cd.c
Author : Abhishek Mandal
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 29th September 2025
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	char name[100];
	printf("enter the name of fifo file: ");
	scanf("%s", name);

	int choice;
	printf("choose an option:\n1.mknod sytem call\n2.mkfifo system call\n");
	scanf("%d", &choice);

	switch(choice){
		case 1:
			printf("using mknod system call...\n");
			mknod(name, __S_IFIFO | 0744, 0);
			printf("FIFO file created using mknod\n");
			break;
		case 2:
			printf("using mkfifo system call...\n");
			mkfifo(name, 0744);
			printf("FIFO file created using mkfifo\n");
			break;
		default:
			printf("invalid choise\n");
			break;
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 19cd.c
ab@ab:~/handson2$ ./a.out
enter the name of fifo file: ab
choose an option:
1.mknod sytem call
2.mkfifo system call
1
using mknod system call...
FIFO file created using mknod
ab@ab:~/handson2$ ./a.out
enter the name of fifo file: 1
choose an option:
1.mknod sytem call
2.mkfifo system call
2
using mkfifo system call...
FIFO file created using mkfifo
============================================================================
*/
