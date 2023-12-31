
The original Unix operating system was designed and implemented by Ken Thompson and Dennis Ritchie at AT&T Bell Laboratories in the early 1970s.
The first version of the UNIX shell, called the Thompson shell or sh, was written by Ken Thompson himself. Ken Thompson developed the shell as part of the original UNIX operating system at Bell Laboratories in the early 1970s.

a shell works by accepting user commands, parsing them, locating the corresponding executable, creating a new process to execute the command, waiting for the command to complete, and displaying the output. It provides an interface between the user and the operating system, allowing users to interact with the system by executing commands and managing resources. Shells also offer additional features like environment variables, command history, piping, redirection, and scripting capabilities.

processes can be created by using system calls or functions provided by the operating system or programming language. In Unix-like systems, the fork() system call is commonly used to create a new process by duplicating the existing process. In Windows systems, the CreateProcess function is often used to create new processes, specifying parameters such as the executable file and process attributes.

PID (Process ID) is a unique identifier assigned to each running process, while PPID (Parent Process ID) represents the PID of the parent process that created a particular process. PID helps track and manage individual processes, while PPID establishes the hierarchical relationship between processes.

you can manipulate the environment of the current process using functions like getenv() to retrieve the value of an environment variable, setenv() to set or modify the value of an environment variable, and unsetenv() to remove an environment variable from the process's environment.

In short, the main difference between a function and a system call is that a function is a block of reusable code within a program or library that operates in user mode and is invoked within the same program, while a system call is a request made by a program to the operating system kernel for privileged operations or accessing system resources. System calls allow user programs to interact with the operating system and are executed in kernel mode.

the shell uses the PATH environment variable to find programs by searching the directories specified in PATH. It looks for an executable file with a matching name in each directory, executing the first one found. If no executable is found, it displays a "command not found" error.

you can execute another program using the execve() system call in the following steps:

    Prepare the arguments: Create an array of strings that contains the program name and its arguments. This array should be terminated with a NULL pointer.

    Prepare the environment variables (optional): If the executed program requires specific environment variables, create an array of strings representing the environment variables. This array should also be terminated with a NULL pointer.

    Call execve(): Invoke the execve() system call, providing the path to the program binary, the argument array, and the environment variable array as parameters.

Here's a C code snippet demonstrating the usage of execve():
c

#include <unistd.h>

int main() {
    char *args[] = { "program_name", "arg1", "arg2", NULL };
    char *env[] = { "VAR1=value1", "VAR2=value2", NULL };
    
    execve("/path/to/program", args, env);
    
    // If execve returns, an error occurred
    perror("execve");
    return 1;
}

In this example:

    The args array contains the program name followed by its arguments. The last element is set to NULL.
    The env array represents the environment variables needed by the program.
    The execve() system call is invoked, passing the program path, argument array, and environment variable array.
    If execve() returns, it means an error occurred. The perror() function is used to print an error message.


the three common prototypes of the main function are:

    int main(void): Takes no arguments and returns an integer value. Used when the program does not require command-line arguments.
    int main(int argc, char *argv[]): Takes command-line arguments as parameters. argc represents the number of arguments, and argv is an array of strings containing the arguments.
    int main(int argc, char *argv[], char *envp[]): Similar to the previous prototype but includes the envp[] parameter, representing environment variables passed to the program.

to suspend the execution of a process until one of its children terminates, you can use the wait() system call or its variants. Here's a summary of the steps:

    Fork a child process: Use the fork() system call to create a child process from the parent process.

    Child process execution: In the child process, execute the desired code or program using execve() or other execution-related functions.

    Parent process execution: In the parent process, use the wait() system call or its variants (e.g., waitpid()) to suspend its execution until one of its child processes terminates.

Here's an example in C:
c

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process code
        // Execute the desired code or program
        // Child process terminates when done
        // ...
    } else if (child_pid > 0) {
        // Parent process code
        // Wait for the child process to terminate
        int status;
        pid_t terminated_child_pid = wait(&status);
        
        if (terminated_child_pid > 0) {
            if (WIFEXITED(status)) {
                printf("Child process terminated normally. Exit status: %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child process terminated by a signal. Signal number: %d\n", WTERMSIG(status));
            }
        } else {
            perror("wait");
        }
    } else {
        // Error handling if fork fails
        perror("fork");
        return 1;
    }

    return 0;
}

In this example:

    The parent process forks a child process using fork().
    In the child process, the desired code or program is executed.
    The parent process uses wait() to suspend its execution until one of its child processes terminates.
    After the child process terminates, the parent process can obtain information about the termination status using wait() and perform further actions accordingly.

Note that the wait() system call can also be used with options and more advanced handling using waitpid().

EOF (End-of-File) is a special value that represents the end of a file or input stream. It is used to indicate that there are no more data or characters to be read from an input source.

EOF is typically represented by the constant EOF, which is defined in the standard input/output header file <stdio.h> in C. It is a negative integer value, often -1, that is returned by input/output functions when they encounter the end of a file or an error condition.
Here's a simple example that shows how to read characters from standard input until the end of the file is reached:
c

#include <stdio.h>

int main() {
    int ch;

    while ((ch = getchar()) != EOF) {
        // Process the character
        putchar(ch);
    }

    return 0;
}

In this example, the getchar() function is used to read characters from standard input. The loop continues until getchar() returns EOF, indicating the end of the input stream.

It's important to note that EOF is a symbolic constant and not an actual character. It is used to indicate a condition rather than representing a specific character value.


The core part of any Linux shell is the Command Line Interpreter, or CLI.

In order to follow this tutorial, you will need the following:

    A working GNU/Linux system (I personally use Ubuntu and Fedora, but feel free to use your favorite Linux distribution).
    GCC (the GNU Compiler Collection) to compile the code.
    A text editor to write the code (I personally use GEdit, but you can use Vim, Emacs, or any other editor as well).
    How to program in C.

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
