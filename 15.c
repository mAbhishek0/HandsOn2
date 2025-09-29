/*
============================================================================
Name : 15.c
Author : Abhishek Mandal
Description : Write a simple program to send some data from parent to
the child process.
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(){
	char buff[50];
	int fd[2];
	pipe(fd);
	
	if(fork()){
		close(fd[0]);
		write(fd[1], "hello from parent process\n", 27);
	} else {
		close(fd[1]);
		read(fd[0], buff, sizeof(buff));
		printf("message from parent: %s\n", buff);
	}
	wait(0);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 15.c
ab@ab:~/handson2$ ./a.out
message from parent: hello from parent process
============================================================================
*/

