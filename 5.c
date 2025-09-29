/*
============================================================================
Name : 5.c
Author : Abhishek Mandal
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/sysinfo.h>
#include<limits.h>

int main(){
	long argMax, procMax, openMax, pageSize, totalPages, avlPages, ticks;
	
	argMax = sysconf(_SC_ARG_MAX);
	printf("maximum length of the arguments to the exec family of functions:  %ld\n",argMax);
	
	procMax = sysconf(_SC_CHILD_MAX);
	printf("maximum number of simultaneous process per use id: %ld\n", procMax);

	openMax = sysconf(_SC_OPEN_MAX);
	printf("maximum number of open files: %ld\n", openMax);

	pageSize = sysconf(_SC_PAGESIZE);
	printf("size of a page: %ld bytes\n", pageSize);

	ticks = sysconf(_SC_CLK_TCK);
	printf("number of clock ticks per second: %ld\n", ticks);

	totalPages = sysconf(_SC_PHYS_PAGES);
	printf("total number of pages in memory: %ld\n", totalPages);

	avlPages = sysconf(_SC_AVPHYS_PAGES);
	printf("number of currently available pages in memory: %ld\n", avlPages);

	return 0;
}


/*
============================================================================
output:
ab@ab:~/handson2$ cc 5.c
ab@ab:~/handson2$ ./a.out
maximum length of the arguments to the exec family of functions:  2097152
maximum number of simultaneous process per use id: 61002
maximum number of open files: 1024
size of a page: 4096 bytes
number of clock ticks per second: 100
total number of pages in memory: 3943625
number of currently available pages in memory: 1173593
============================================================================
*/
