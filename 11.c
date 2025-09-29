/*
============================================================================
Name : 11.c
Author : Abhishek Mandal
Description : Write a program to ignore a SIGINT signal then reset the 
default action of the SIGINT signal -use sigaction system call
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<bits/sigaction.h>

int main(){
	struct sigaction sa;

	sa.sa_handler = SIG_IGN;
	printf("SIGINT WILL BE IGNORED FOR 5 SECONDS NOW.\n");
	sigaction(SIGINT, &sa, NULL);
	sleep(5);
	printf(" SIGINT WILL NOW BE ALLOWED\n");
	sa.sa_handler = SIG_DFL;
	printf("default of SIGINT set");
	sigaction(SIGINT, &sa, NULL);

	while(1);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 11.c
ab@ab:~/handson2$ ./a.out
SIGINT WILL BE IGNORED FOR 5 SECONDS NOW.
^C^C^C SIGINT WILL NOW BE ALLOWED
^C
============================================================================
*/
