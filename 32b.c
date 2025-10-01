/*
============================================================================
Name : 32b.c
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
#include<sys/shm.h>
#include<stdio.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(){
    key_t skey, shkey;
    int semid, shmid;
    char *data;

    skey = ftok(".", 200);
    shkey = ftok(".", 201);

    semid = semget(skey, 1, 0666 | IPC_CREAT);
    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    shmid = shmget(shkey, 1024, 0666 | IPC_CREAT);
    data = shmat(shmid, (void *)0, 0);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = 0;

    sb.sem_op = -1;
    semop(semid, &sb, 1);

    printf("Enter text to write to shared memory:\n");
    scanf("%[^\n]", data);

    sb.sem_op = 1;
    semop(semid, &sb, 1);

    printf("Data written to shared memory.\n");
    return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 32b.c
ab@ab:~/handson2$ ./a.out
Enter text to write to shared memory:
hello!
Data written to shared memory.
ab@ab:~/handson2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 10         ab         600        524288     2          dest         
0x00000000 32782      ab         600        524288     2          dest         
0x00000000 32783      ab         600        4194304    2          dest         
0x00000000 32784      ab         600        67108864   2          dest         
0x00000000 32787      ab         600        524288     2          dest         
0x00000000 32788      ab         600        4194304    2          dest         
0x00000000 32789      ab         600        33554432   2          dest         
0xffffffff 196641     ab         666        1024       0                       
0xc9062bca 196647     ab         666        1024       0                       
0x00000000 163885     ab         600        524288     2          dest         
0x00000000 32814      ab         600        524288     2          dest         
0x00000000 131124     ab         600        524288     2          dest  
ab@ab:~/handson2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0xffffffff 9          ab         666        1         
0xc8062bca 10         ab         666        1  
============================================================================
*/