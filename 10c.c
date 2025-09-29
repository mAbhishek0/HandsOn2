/*
============================================================================
Name : 10b.c
Author : Abhishek Mandal
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void handler(int signum){
	printf("caught SIGFPE\n");
	exit(1);
}
int main(){
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGFPE, &sa, NULL);
	int n = 1 / 0;
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 10c.c
10c.c: In function ‘main’:
10c.c:25:19: warning: division by zero [-Wdiv-by-zero]
   25 |         int n = 1 / 0;
      |                   ^
ab@ab:~/handson2$ ./a.out
caught SIGFPE
============================================================================
*/

