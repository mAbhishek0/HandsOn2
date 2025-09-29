#/*
#============================================================================
#Name : 19c.c
#Author : Abhishek Mandal
#Description : Create a FIFO file by
#a. mknod command
#b. mkfifo command
#c. use strace command to find out, which command (mknod or mkfifo) is better.
#c. mknod system call
#d. mkfifo library function
#Date: 29th September 2025
#============================================================================
#*/
#!/bin/bash
#!/bin/bash
# Use strace to see which system calls are used internally

FIFO1="fifo_mkfifo"
FIFO2="fifo_mknod"
rm -f $FIFO1 $FIFO2

echo "Tracing mkfifo..."
strace -o trace_mkfifo.log mkfifo $FIFO1

echo "Tracing mknod..."
strace -o trace_mknod.log mknod $FIFO2 p

echo "System call used by mkfifo:"
grep mknod trace_mkfifo.log

echo "System call used by mknod:"
grep mknod trace_mknod.log

echo "Check generated FIFO files:"
ls -l $FIFO1 $FIFO2
sleep 10
#/*
#============================================================================
#output:
#Tracing mkfifo...
#Tracing mknod...
#System call used by mkfifo:
#mknodat(AT_FDCWD, "fifo_mkfifo", S_IFIFO|0666) = 0
#System call used by mknod:
#execve("/usr/bin/mknod", ["mknod", "fifo_mknod", "p"], 0x7ffd5e55cef0 /* 43 vars */) = 0
#mknodat(AT_FDCWD, "fifo_mknod", S_IFIFO|0666) = 0
#Check generated FIFO files:
#prw-rw-r-- 1 ab ab 0 Sep 30 00:39 fifo_mkfifo
#prw-rw-r-- 1 ab ab 0 Sep 30 00:39 fifo_mknod
#============================================================================
#*/