/*
============================================================================
Name : 32d.c
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

int main(){
    key_t key = ftok(".", 300);
    int semid = semget(key, 1, 0);

    int ret = semctl(semid, 0, IPC_RMID);
    if(ret != -1)
        printf("Semaphore removed successfully\n");
    else
        printf("Semaphore removal failed\n");

    return 0;
}

/*
============================================================================
output:
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 9          ab         666        1         
0xc8062bca 10         ab         666        1         
0x2c062bca 11         ab         666        1         

ab@ab:~/handson2$ cc 32d.c
ab@ab:~/handson2$ ./a.out
Semaphore removed successfully
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 9          ab         666        1         
0xc8062bca 10         ab         666        1 
============================================================================
*/