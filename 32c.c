/*
============================================================================
Name : 32c.c
Author : Abhishek Mandal
Description : Write a program to implement semaphore to protect any 
critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 1st October 2025
============================================================================
*/
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(){
    key_t key = ftok(".", 300);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    union semun arg;
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = 0;

    for(int i=1;i<=4;i++){
        sb.sem_op = -1;
        semop(semid, &sb, 1);

        printf("Process %d got resource\n", i);

        sleep(1);

        printf("Process %d releasing resource\n", i);

        sb.sem_op = 1;
        semop(semid, &sb, 1);
    }

    return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 32c.c
ab@ab:~/handson2$ ./a.out
Process 1 got resource
Process 1 releasing resource
Process 2 got resource
Process 2 releasing resource
Process 3 got resource
Process 3 releasing resource
Process 4 got resource
Process 4 releasing resource
============================================================================
*/