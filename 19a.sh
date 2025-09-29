#/*
#============================================================================
#Name : 19a.c
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
# Create a FIFO using the mknod command
FIFO_NAME="fifo_mknod"

# Remove if it already exists
rm -f $FIFO_NAME

echo "Creating FIFO using mknod..."
mknod $FIFO_NAME p

echo "FIFO created:"
ls -l $FIFO_NAME
sleep 10
#/*
#============================================================================
#output:
#Creating FIFO using mknod...
#FIFO created:
#prw-rw-r-- 1 ab ab 0 Sep 30 00:31 fifo_mknod
#============================================================================
#*/