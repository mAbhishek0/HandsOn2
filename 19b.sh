#/*
#============================================================================
#Name : 19b.c
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
# Create a FIFO using the mkfifo command
FIFO_NAME="fifo_mkfifo"

rm -f $FIFO_NAME

echo "Creating FIFO using mkfifo..."
mkfifo $FIFO_NAME

echo "FIFO created:"
ls -l $FIFO_NAME
sleep 10
#/*
#============================================================================
#output:
#Creating FIFO using mkfifo...
#FIFO created:
#prw-rw-r-- 1 ab ab 0 Sep 30 00:32 fifo_mkfifo
#============================================================================
#*/
