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
		close(fd[0]);
		dup2(fd[1], 1);
		execlp("ls", "ls", "-l", (char*)NULL);
	} else {
		close(fd[1]);
		dup2(fd[0], 0);
		execlp("wc", "wc", (char *) NULL);
	}
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 17c.c
ab@ab:~/handson2$ ./a.out
     35     308    1486
============================================================================
*/

