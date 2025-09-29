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
#include<signal.h>
#include<sys/time.h>

void handler(int signo){
	printf("itimer expired (SIGALRM)\n");
}

int main(){
	struct itimerval timer;
	signal(SIGALRM, handler);

	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 0;

	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 10;

	int temp = setitimer(ITIMER_REAL, &timer, 0);
	if(temp == -1){
		perror("itimer error");
		exit(1);
	}

	while(1);

}


/*
============================================================================
output:
ab@ab:~/handson2$ ./a.out
itimer expired (SIGALRM)
itimer expired (SIGALRM)
itimer expired (SIGALRM)
itimer expired (SIGALRM)
============================================================================
*/
