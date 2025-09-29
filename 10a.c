/*
============================================================================
Name : 10a.c
Author : Abhishek Mandal
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int signum){
	printf("caught SIGSEGV\n");
	exit(1);
}

int main(){
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGSEGV, &sa, NULL);
	int *p = NULL;
	*p = 0;
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 10a.c
ab@ab:~/handson2$ ./a.out
caught SIGSEGV
============================================================================
*/
