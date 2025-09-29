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
	printf("thread &d is executing\n", threadID);
	return NULL;
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
ab@ab:~/handson2$ cc 5.c
ab@ab:~/handson2$ ./a.out
maximum length of the arguments to the exec family of functions:  2097152
maximum number of simultaneous process per use id: 61002
maximum number of open files: 1024
size of a page: 4096 bytes
number of clock ticks per second: 100
total number of pages in memory: 3943625
number of currently available pages in memory: 1173593
============================================================================
*/
