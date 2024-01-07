a process is an instance of an executing program, that has a unique process id.this process id is used by many functions and system calls to interact with and manipulate process.in order to retrive currrent id use system call <b>getpid</b>

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    __pid_t my_pid; //process id aka child process
    __pid_t my_ppid; //parent process id

    my_pid = getpid();
    my_ppid = getppid();

    printf("%u\n", my_pid);
    printf("%u\n", my_ppid);
    return (0);
}
<center>a program to demonstarate pid and getpid</center>

pid_max is a kernel parameter in linux system that determines the max process id value that can be assigned to a process. The process ID is a unique identifier assigned to each running process in the operating system.

the defaultvalue of pid_max varies depending on linux distribution and kernel version.in older systems typically set to 32,768

<textarea>#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum pid(pid_max): $pid_max"</textarea>

<center>a shell script that prints the maximum value a process ID can be.</center>

<textarea>#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 1;
    while (argv[i] != NULL) {
        printf("%s\n", argv[i]);
        i++;
    }
    return 0;
}</textarea>

2. command line to av

Write a function that splits a string and returns an array of each word of the string.

The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process that calls fork). Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.
