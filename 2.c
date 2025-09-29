/*
============================================================================
Name : 2.c
Author : Abhishek Mandal
Description : Write a program to print the system resource limits. 
Use getrlimit system call.
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/resource.h>

int main(){
	int resources[] = {RLIMIT_CPU, RLIMIT_FSIZE, RLIMIT_DATA,
	    RLIMIT_STACK, RLIMIT_CORE, RLIMIT_RSS,RLIMIT_NPROC,
	    RLIMIT_NOFILE, RLIMIT_AS,RLIMIT_LOCKS, RLIMIT_SIGPENDING,
	    RLIMIT_MSGQUEUE, RLIMIT_NICE, RLIMIT_RTPRIO, RLIMIT_RTTIME};
	
	char *rname[] = {"CPU time", "Process file size", "max data segment",
		"max stack size", "max core file size", "max resdent set size", 
		"max no. of process", "max fd open", "max locked memory",
		"max address space", "max file locks", "max no. of pending signals",
		"max bytes in msg queue", "max nice priority increment", "max real time priority"
			 "max cpu time for rt process"};
	for(int i = 0; i < 15; i++){
		struct rlimit limit;
		if(getrlimit(resources[i], &limit) == -1){
			printf("error getting %s limit: %s\n", rname[i], strerror(errno));
			continue;
		}
		printf("resource: %s\n",rname[i]);
		printf("	Soft Limit: ");
		if(limit.rlim_cur == RLIM_INFINITY){
			printf("unlimited\n");
		} else{
			printf("%ld\n", limit.rlim_cur);
		}
		printf("	Hard Limit: ");
		if(limit.rlim_max == RLIM_INFINITY){
			printf("unlimited\n");
		} else {
			printf("%ld\n", limit.rlim_max);
		}
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 2.c
ab@ab:~/handson2$ ./a.out
resource: CPU time
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: Process file size
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: max data segment
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: max stack size
	Soft Limit: 8388608
	Hard Limit: unlimited
resource: max core file size
	Soft Limit: 0
	Hard Limit: unlimited
resource: max resdent set size
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: max no. of process
	Soft Limit: 61002
	Hard Limit: 61002
resource: max fd open
	Soft Limit: 1024
	Hard Limit: 1048576
resource: max locked memory
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: max address space
	Soft Limit: unlimited
	Hard Limit: unlimited
resource: max file locks
	Soft Limit: 61002
	Hard Limit: 61002
resource: max no. of pending signals
	Soft Limit: 819200
	Hard Limit: 819200
resource: max bytes in msg queue
	Soft Limit: 0
	Hard Limit: 0
resource: max nice priority increment
	Soft Limit: 0
	Hard Limit: 0
resource: max real time prioritymax cpu time for rt process
	Soft Limit: unlimited
	Hard Limit: unlimited
============================================================================
*/
