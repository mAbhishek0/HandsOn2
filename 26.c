/*
============================================================================
Name : 26.c
Author : Abhishek Mandal
Description : Write a program to send messages to the message queue.
 Check $ipcs -q
Date: 30th September 2025
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct msg{
	long int mType;
	char msg[100];
};
int main(){
	key_t key = ftok(".", 1234);
	int mqid = msgget(key, IPC_CREAT |0666);
	struct msg mymsg;
	mymsg.mType = 10;
	printf("enter the message:\n");
	scanf("%[^\n]", mymsg.msg);
	int size = strlen(mymsg.msg);
	msgsnd(mqid, &mymsg, size + 1, 0);
	return 0;
}


/*
============================================================================
output:
ab@ab:~/handson2$ cc 26.c
ab@ab:~/handson2$ ./a.out
enter the message:
hello
ab@ab:~/handson2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          ab         666        0            0           
0x40062bca 1          ab         0          0            0           
0x400621d8 2          ab         0          0            0           
0x39062bca 3          ab         666        0            0           
0xd2062bca 4          ab         744        22           4           

ab@ab:~/handson2$ ./a.out
enter the message:
hi
ab@ab:~/handson2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          ab         666        0            0           
0x40062bca 1          ab         0          0            0           
0x400621d8 2          ab         0          0            0           
0x39062bca 3          ab         666        0            0           
0xd2062bca 4          ab         744        25           5  
============================================================================
*/