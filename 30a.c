/*
============================================================================
Name : 30a.c
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
	shmid = shmget(key, 1024, IPC_CREAT | 0744);
	data = shmat(shmid,(void *)0, 0);
	printf("enter the text: ");
	scanf("%[^\n]", data);
	printf("shared memory id is: %d\n", shmid);
	return 0;
}
	
/*
============================================================================
output:
ab@ab:~/handson2$ cc 30a.c
ab@ab:~/handson2$ ./a.out
enter the text: hello!
shared memory id is: 163852
ab@ab:~/handson2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 7          ab         600        524288     2          dest         
0x00000000 163850     ab         600        524288     2          dest         
0x57256430 163851     ab         744        1024       0                       
0xc8062bca 163852     ab         744        1024       0                       
0x00000000 65554      ab         600        524288     2          dest         
0x00000000 65560      ab         600        16777216   2          dest         
0x00000000 131101     ab         600        524288     2          dest         
0x00000000 35         ab         600        524288     2          dest         
0x00000000 36         ab         600        4194304    2          dest         
0x00000000 37         ab         600        67108864   2          dest         
0x00000000 32807      ab         600        4194304    2          dest         
0x00000000 40         ab         600        524288     2          dest         
0x00000000 41         ab         600        4194304    2          dest         
0x00000000 42         ab         600        33554432   2          dest         
0x00000000 131124     ab         600        524288     2          dest         
0x00000000 62         ab         600        67108864   2          dest   
============================================================================
*/
