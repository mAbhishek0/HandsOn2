/*
============================================================================
Name : 17a.c
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
		dup(fd[1]);
		execlp("ls", "ls", "-l", (char*)NULL);
	} else {
		close(0);
		close(fd[1]);
		dup(fd[0]);
		execlp("wc", "wc", (char *) NULL);
	}
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 17a.c
ab@ab:~/handson2$ ./a.out
     33     290    1398
============================================================================
*/
