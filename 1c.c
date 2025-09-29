/*
============================================================================
Name : 1a.c
Author : Abhishek Mandal
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>

void handler(int signo){
	printf("itimer expired (SIGPROF)\n");
}

int main(){
	struct itimerval timer;
	signal(SIGPROF, handler);

	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 10;

	int temp = setitimer(ITIMER_PROF, &timer, 0);

	if(temp != 0){
		perror("itimer error");
	}

	while(1){
		int pid = getpid();
	}
}
/*
============================================================================
output:
ab@ab:~/handson2$ ./a.out
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
itimer expired (SIGPROF)
============================================================================
*/
