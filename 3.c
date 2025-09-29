/*
============================================================================
Name : 3.c
Author : Abhishek Mandal
Description : Write a program to set (any one) system resource 
limit. Use setrlimit system calil.
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	struct rlimit limit;
	limit.rlim_cur = 5;
	limit.rlim_max = 10;

	if(setrlimit(RLIMIT_CPU, &limit) == -1){
		perror("error setting cpu limit");
		exit(1);
	}

	printf("cpu soft limit set to 5 sec and hard limit to 10 sec\n");

	while(1);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 3.c
ab@ab:~/handson2$ ./a.out
cpu soft limit set to 5 sec and hard limit to 10 sec
CPU time limit exceeded (core dumped)
============================================================================
*/
