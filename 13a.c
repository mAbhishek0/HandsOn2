/*
============================================================================
Name : 13a.c
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
void handler(int signum){
	printf("signal caught: %d\n", signum);
	exit(0);
}

int main(){
	printf("receiver pid: %d\n", getpid());

	struct sigaction sa;

	sa.sa_handler = handler;
	while(1){
		sigaction(SIGSTOP, &sa, NULL);
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 13a.c -o 13a.out
ab@ab:~/handson2$ ./13a.out
receiver pid: 26265

[1]+  Stopped                 ./13a.out
============================================================================
*/

