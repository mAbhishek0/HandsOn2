/*
============================================================================
Name : 9.c
Author : Abhishek Mandal
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(){
	printf("pressing ctrl+c will now be ignored.\n");
	signal(SIGINT, SIG_IGN);

	sleep(5);

	printf("\nSIGINT is now reset to default action\n");
	signal(SIGINT, SIG_DFL);

	while(1){
		printf("press ctrl+c to terminate\n");
		sleep(2);
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 9.c
ab@ab:~/handson2$ ./a.out
pressing ctrl+c will now be ignored.
^C^C^C^C^C
SIGINT is now reset to default action
press ctrl+c to terminate
^C
============================================================================
*/
