/*
============================================================================
Name : 6.c
Author : Abhishek Mandal
Description : Write a simple program to create three threads.
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>

void *foo(void *p){
	int threadID = *((int*)p);
	printf("thread %d is executing\n", threadID);
}

int main(){
	pthread_t id[3];

	int id1 = 1;
	int id2 = 2;
	int id3 = 3;

	pthread_create(&id[0], NULL, foo, &id1);
	pthread_create(&id[1], NULL, foo, &id2);
	pthread_create(&id[2], NULL, foo, &id3);

	pthread_join(id[0], NULL);
	pthread_join(id[1], NULL);
	pthread_join(id[2], NULL);

	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 6.c
ab@ab:~/handson2$ ./a.out
thread 1 is executing
thread 2 is executing
thread 3 is executing
============================================================================
*/
