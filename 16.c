/*
============================================================================
Name : 16.c
Author : Abhishek Mandal
Description : Write a program to send and receive data from parent to
child vice versa. Use two way communication
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int fd1[2], fd2[2];
	char buff1[50], buff2[50];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1], "hello from child process!\n", 27);
		read(fd2[0], buff2, sizeof(buff2));
		printf("messasge form parent: %s\n", buff2);
	} else {
		close(fd1[1]);
		close(fd2[0]);
		write(fd2[1], "hello from parent process!\n", 28);
		read(fd1[0], buff1, sizeof(buff1));
		printf("message from child: %s\n", buff1);
	}
	wait(0);
	return 0;
}
/*
============================================================================
output:
aab@ab:~/handson2$ ./a.out
message from child: hello from child process!
messasge form parent: hello from parent process!
============================================================================
*/

