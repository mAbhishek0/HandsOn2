/*
============================================================================
Name : 32a.c
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
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}


void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("ticketfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    union semun arg;
    arg.val = 1; 
    semctl(semid, 0, SETVAL, arg);

    int fd = open("ticket.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) { 
		perror("open"); exit(1); 
	}


    sem_wait(semid);

    int ticket;
    read(fd, &ticket, sizeof(ticket));
    if(ticket == 0) ticket = 100;

    printf("Your ticket number is %d\n", ticket);
    ticket++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    sem_signal(semid);

    close(fd);
    return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 32a.c
ab@ab:~/handson2$ ./a.out
Your ticket number is 103
ab@ab:~/handson2$ ./a.out
Your ticket number is 104
============================================================================
*/