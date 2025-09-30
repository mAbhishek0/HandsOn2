/*
============================================================================
Name : 23.c
Author : Abhishek Mandal
Description : Write a program to print the maximum number of files can be 
opened within a process and size of a pipe (circular buffer).
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
	long pipeBuff, openMax;
	int fd[2];
	pipe(fd);

	pipeBuff = fpathconf(fd[0], _PC_PIPE_BUF);
	openMax = sysconf(_SC_OPEN_MAX);
	printf("size of pipe(circular buffer) is: %ld\n", pipeBuff);
	printf("maximum number of open files is: %ld\n", openMax); 	
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 23.c
ab@ab:~/handson2$ ./a.out
size of pipe(circular buffer) is: 4096
maximum number of open files is: 1048576
============================================================================
*/
