/*
============================================================================
Name : 12.c
Author : Abhishek Mandal
Description : Write a program to create an orphan process. Use kill 
system call to send SIGKILL signal to the parent process from the child process
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main(){
	if(!fork()){
		sleep(5);
		printf("child process pid: %d\n", getpid());
		kill(getppid(), SIGKILL);
		printf("parent process killed\n");
		sleep(5);
		printf("the new parent is: %d\n", getppid());
		exit(0);
	} else {
		printf("parent pid: %d\n", getpid());
		sleep(10);
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 12.c
ab@ab:~/handson2$ ./a.out
parent pid: 20709
child process pid: 20710
parent process killed
Killed
ab@ab:~/handson2$ the new parent is: 3534
============================================================================
*/

