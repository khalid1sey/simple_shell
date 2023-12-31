

Introduction:
The Unix operating system revolutionized computing with its modular design and powerful features. One of its key components is the shell, which serves as a user interface to interact with the operating system. In this article, we will delve into the key concepts and functionalities of Unix shells, process management, environment manipulation, system calls, and more. Let's explore the foundations of Unix shells and how they facilitate efficient interaction between users and the operating system.

    Unix Shells:
    1.1 The Origins of Unix Shells:
    The original Unix shell, known as the Thompson shell or sh, was developed by Ken Thompson in the early 1970s. We'll briefly touch upon its inception and the role it played in early Unix systems.

1.2 Shell Basics:
Learn about the fundamental workings of a shell, including its purpose, command parsing, execution, and output handling. We'll also explore features like environment variables, command history, piping, redirection, and scripting capabilities that enhance the shell's functionality.

    Process Management:
    2.1 Process Creation:
    Discover how processes are created in Unix-like systems and Windows, focusing on system calls such as fork() and CreateProcess(). Understand the significance of Process IDs (PID) and Parent Process IDs (PPID) in managing and tracking processes.

2.2 Executing Programs:
Explore the execve() system call and its usage to execute other programs. Step through the process of preparing arguments and environment variables, and see how execve() replaces the current process with the new program.

    Environment Manipulation:
    Learn how to manipulate the environment of a process using functions like getenv(), setenv(), and unsetenv(). Understand how these functions allow you to retrieve, modify, and remove environment variables within a process.

    Functions vs. System Calls:
    Distinguish between functions and system calls, understanding their roles and differences. Gain insight into how functions operate within a program, while system calls provide a means to interact with the operating system and access system resources.

    PATH and Program Execution:
    Learn how the shell uses the PATH environment variable to locate programs. Explore the process of searching directories specified in PATH to find an executable file, and understand how the shell handles "command not found" scenarios.

    Main Function Prototypes:
    Discover the three common prototypes of the main function in C programs, highlighting their purposes. Understand the differences between int main(void), int main(int argc, char *argv[]), and int main(int argc, char *argv[], char *envp[]), and when to use each.

    Suspending Processes with Wait:
    Understand how the wait() system call and its variants allow a process to suspend its execution until one of its child processes terminates. Follow the steps involved in forking a child process, executing code in the child, and waiting for the child process to complete in the parent.

    The Concept of EOF:
    Explore the concept of End-of-File (EOF) and its significance in indicating the end of a file or input stream. Understand how EOF is represented, how it is utilized in input/output functions, and its role in processing data until the end of a file is reached.

Conclusion:
Unix shells provide a powerful interface for users to interact with the operating system, enabling command execution, process management, and environment manipulation. Understanding the foundations of shells and process management is key to efficiently utilizing the capabilities of Unix-like systems. By grasping concepts like system calls, environment variables, and the role of the main function, users can harness the power of Unix shells to optimize their workflow and enhance their productivity.

<h3>Mandatory Tasks</h3>

0. Betty would be proud

Write a beautiful code that passes the Betty checks


1. Simple shell 0.1

Write a UNIX command line interpreter.

    Usage: simple_shell

Your Shell should:

    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

    use the PATH
    implement built-ins
    handle special characters : ", ', `, \, *, &, #
    be able to move the cursor
    handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…


2. Simple shell 0.2

Simple shell 0.1 +

    Handle command lines with arguments


3. Simple shell 0.3

Simple shell 0.2 +

    Handle the PATH
    fork must not be called if the command doesn’t exist


4. Simple shell 0.4

Simple shell 0.3 +

    Implement the exit built-in, that exits the shell
    Usage: exit
    You don’t have to handle any argument to the built-in exit


5. Simple shell 1.0

Simple shell 0.4 +

    Implement the env built-in, that prints the current environment
