/*
============================================================================
Name : 8a.c
Author : Abhishek Mandal
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void handler(int signum){
	printf("caught SIGINT:(ctrl+c)\n");
	exit(0);
}

int main(){
	signal(SIGINT, handler);
	printf("press ctrl+c to trigger SIGINT\n");
	while(1);
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 8b.c
ab@ab:~/handson2$ ./a.out
press ctrl+c to trigger SIGINT
^Ccaught SIGINT:(ctrl+c)
============================================================================
*/
