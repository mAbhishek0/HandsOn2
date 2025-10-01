/*
============================================================================
Name : 31b.c
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
	key_t key = ftok(".", 234);
	int semid = semget(key, 3, 0666 |IPC_CREAT);
	union semun arg;
	arg.val = 10;
	semctl(semid, 0, SETVAL, arg);
	printf("counting semaphore created with ID %d &initialized to 1\n", semid);
	return 0;
}

	
/*
============================================================================
output:
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     

ab@ab:~/handson2$ cc 31b.c
ab@ab:~/handson2$ ./a.out
counting semaphore created with ID 2 &initialized to 1
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xea062bca 8          ab         666        3   
ab@ab:~/handson2$ ipcs -s -i 8

Semaphore Array semid=8
uid=1000         gid=1000        cuid=1000       cgid=1000
mode=0666, access_perms=0666
nsems = 3
otime = Not set                   
ctime = Wed Oct  1 11:13:41 2025  
semnum     value      ncount     zcount     pid       
0          10         0          0          23931     
1          0          0          0          0         
2          0          0          0          0 
============================================================================
*/
