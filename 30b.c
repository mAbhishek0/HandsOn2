/*
============================================================================
Name : 30b.c
Author : Abhishek Mandal
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 30th September 2025
============================================================================
*/
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main(){
	int key, shmid;
	char *data;
	key = ftok(".", 456);
	shmid = shmget(key, 1024, 0);
	data = shmat(shmid, (void *)0, SHM_RDONLY);
	printf("enter data to be put into shard memory:\n");
	scanf("%[^\n]", data);
	return 0;
}
	
/*
============================================================================
output:
ab@ab:~/handson2$ cc 30b.c
ab@ab:~/handson2$ ./a.out
enter data to be put into shard memory:
hello!
Segmentation fault (core dumped)
============================================================================
*/

