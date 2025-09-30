/*
============================================================================
Name : 30c.c
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
	key = ftok(".",456);
	shmid = shmget(key, 1024, IPC_CREAT | 0666);
	data = shmat(shmid, (void *)0, 0);
	int temp = shmdt(data);
	if(temp == 0)
		printf("shm detached successfully\n");
	else 
		printf("shm detachment failed\n");
	return 0;
}
	
/*
============================================================================
output:
ab@ab:~/handson2$ cc 30c.c
ab@ab:~/handson2$ ./a.out
shm detached successfully
============================================================================
*/