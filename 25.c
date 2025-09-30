/*
============================================================================
Name : 25.c
Author : Abhishek Mandal
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 30th September 2025
============================================================================
*/
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<time.h>
int main(){
	key_t key = ftok(".", 12345);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	struct msqid_ds st;

	printf("access permission: %o\n", st.msg_perm.mode);
	printf("uid and gid of owner: %d, %d\n", st.msg_perm.uid, st.msg_perm.gid);
	printf("time of last message sent and received: %u, %u\n",st.msg_perm.cuid, st.msg_perm.cgid);
	printf("time of last change: %s\n", ctime(&st.msg_ctime));
	printf("current number of bytes in queue: %lu\n",st.__msg_cbytes);
	printf("number of messages in queue: %lu\n", st.msg_qnum);
	printf("max bytes allowed in queue: %lu", st.msg_qbytes);
	printf("pid of last msgsnd nd msgrcv: %d, %d\n", st.msg_lspid, st.msg_lrpid);
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ ./a.out
access permission: 0
uid and gid of owner: 0, 524288
time of last message sent and received: 0, 32768
time of last change: Thu Jan  1 05:30:00 1970

current number of bytes in quue: 0
number of messages in queue: 0
max bytes allowed in queue: 0pid of last msgsnd nd msgrcv: 0, 0
============================================================================
*/

