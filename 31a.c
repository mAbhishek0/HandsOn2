/*
============================================================================
Name : 31a.c
Author : Abhishek Mandal
Description : Write a program to create a semaphore and initialize value
to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 30th September 2025
============================================================================
*/
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
int main(){
	key_t key = ftok(".", 123);
	int semid = semget(key, 1, 0666 |IPC_CREAT);
	union semun arg;
	arg.val = 1;
	semctl(semid, 0, SETVAL, arg);
	printf("binary semaphore created with ID %d &initialized to 1\n", semid);
	return 0;
}

	
/*
============================================================================
output:
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     

ab@ab:~/handson2$ cc 31a.c
ab@ab:~/handson2$ ./a.out
binary semaphore created with ID 1 &initialized to 1
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x7b062bca 1          ab         666        1   
============================================================================
*/
