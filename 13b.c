/*
============================================================================
Name : 13b.c
Author : Abhishek Mandal
Description : Write two programs: first program is waiting to catch SIGSTOP
signal, the second program will send the signal (using kill system call).
Find out whether the first program is able to catch the signal or not
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<bits/sigaction.h>
int main(){
	int pid;
	printf("enter the pid of prcess to be stopped:\n");
	scanf("%d", &pid);

	printf("sending SIGSTOP signal to process: %d\n", pid);
	kill(pid, SIGSTOP);
	printf("SIGSTOP sent\n");
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 13b.c -o 13b.out
ab@ab:~/handson2$ ./13b.out
enter the pid of prcess to be stopped:
26265
sending SIGSTOP signal to process: 26265
SIGSTOP sent
============================================================================
*/
