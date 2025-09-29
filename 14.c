/*
============================================================================
Name : 14.c
Author : Abhishek Mandal
Description : Write a simple program to create a pipe, write to the pipe,
read from pipe and display onthe monitor
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int i, j, fd[2];
	char buf[50];
	i = pipe(fd);
	printf("i = %d\n", i);
	j = write(fd[1], "Hello\n", 7);
	read(fd[0], buf, j);
	printf("from the pipe: %s\n", buf);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 14.c
ab@ab:~/handson2$ ./a.out
i = 0
from the pipe: Hello
============================================================================
*/

