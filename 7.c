/*
============================================================================
Name : 7.c
Author : Abhishek Mandal
Description : Write a simple program to print the created thread ids.
Date: 29th September 2025
============================================================================
*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>

void *threadfunction(void *args){
	printf("thread id is: %lu\n",pthread_self());
}

int main(){
	pthread_t mythread[3];

	pthread_create(&mythread[0], NULL, threadfunction, NULL);
	pthread_create(&mythread[1], NULL, threadfunction, NULL);
	pthread_create(&mythread[2], NULL, threadfunction, NULL);

	pthread_join(mythread[0], NULL);
	pthread_join(mythread[1], NULL);
	pthread_join(mythread[2], NULL);

	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 7.c
ab@ab:~/handson2$ ./a.out
thread id is: 133447649588928
thread id is: 133447632803520
thread id is: 133447641196224
============================================================================
*/
