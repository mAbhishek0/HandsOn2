/*
============================================================================
Name : 4.c
Author : Abhishek Mandal
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 28th September 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

unsigned long long rdtsc(){
	unsigned long long low, high;
	asm volatile("rdtsc":"=a"(low), "=d"(high));
	unsigned long long cycle = ((unsigned long long)high << 32) | low;
	return cycle; 
};

int main(){
	unsigned long long start, end;
	start = rdtsc();
	for(int i = 0; i < 100; i++)
		getppid();
	end = rdtsc();

	printf("total cpu cycles for 100 getppid(): %llu", (end - start));
	return 0;
}
/*
============================================================================
output:
ab@ab:~/handson2$ cc 4.c
ab@ab:~/handson2$ ./a.out
total cpu cycles for 100 getppid(): 89146
============================================================================
*/
