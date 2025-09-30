/*
============================================================================
Name : 30d.c
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
	shmid = shmget(key, 1024, 0);
	int temp = shmctl(shmid, IPC_RMID, NULL);
	if(temp != -1)
		printf("smh removed\n");
	return 0;
}
	
/*
============================================================================
output:
ab@ab:~/handson2$ cc 30d.c
ab@ab:~/handson2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 7          ab         600        524288     2          dest         
0x00000000 163850     ab         600        524288     2          dest         
0x57256430 163851     ab         744        1024       0                       
0xc8062bca 163852     ab         744        1024       0                       
0x00000000 65554      ab         600        524288     2          dest         
0x00000000 65560      ab         600        16777216   2          dest         
0x00000000 163868     ab         600        524288     2          dest         
0x00000000 35         ab         600        524288     2          dest         
0x00000000 36         ab         600        4194304    2          dest         
0x00000000 37         ab         600        67108864   2          dest         
0x00000000 32807      ab         600        4194304    2          dest         
0x00000000 40         ab         600        524288     2          dest         
0x00000000 41         ab         600        4194304    2          dest         
0x00000000 42         ab         600        33554432   2          dest         
0x00000000 62         ab         600        67108864   2          dest         

ab@ab:~/handson2$ ./a.out
smh removed
ab@ab:~/handson2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 7          ab         600        524288     2          dest         
0x00000000 163850     ab         600        524288     2          dest         
0x57256430 163851     ab         744        1024       0                       
0x00000000 65554      ab         600        524288     2          dest         
0x00000000 65560      ab         600        16777216   2          dest         
0x00000000 163868     ab         600        524288     2          dest         
0x00000000 35         ab         600        524288     2          dest         
0x00000000 36         ab         600        4194304    2          dest         
0x00000000 37         ab         600        67108864   2          dest         
0x00000000 32807      ab         600        4194304    2          dest         
0x00000000 40         ab         600        524288     2          dest         
0x00000000 41         ab         600        4194304    2          dest         
0x00000000 42         ab         600        33554432   2          dest         
0x00000000 62         ab         600        67108864   2          dest 
============================================================================
*/