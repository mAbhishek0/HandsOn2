/*
============================================================================
Name : 17b.c
Author : Abhishek Mandal
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd[2];
	pipe(fd);
	if(!fork()){
		close(1);
		close(fd[0]);
		fcntl(fd[1], F_DUPFD, 1);
		execlp("ls", "ls", "-l", (char*)NULL);
	} else {
		close(0);
		close(fd[1]);
		fcntl(fd[0],F_DUPFD, 0);
		execlp("wc", "wc", (char *) NULL);
	}
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 17b.c
ab@ab:~/handson2$ ./a.out
     34     299    1442
============================================================================
*/


