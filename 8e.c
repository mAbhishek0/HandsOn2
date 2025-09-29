/*
============================================================================
Name : 8e.c
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
#include<unistd.h>
#include<sys/time.h>

void handler(int signum){
	printf("caught SIGALRM(using setitimer)\n");
	exit(0);
}
int main(){
	struct itimerval timer;
	signal(SIGALRM, handler);
	
	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &timer, NULL);

	while(1);
	return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ cc 8e.c
ab@ab:~/handson2$ ./a.out
caught SIGALRM(using setitimer)
============================================================================
*/
