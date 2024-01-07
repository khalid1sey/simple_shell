
Shaza’s Substack
Discover more from Shaza’s Substack
My Tech Substack
Continue reading
Sign in
Simple Shell
Whiteboarding Simple Shell: A Guide for ALX SE Community ❥ | Beta Version
Mastering Unix Shell Interpreters with Zero Code Knowledge (and a Lot of Coffee)
Shaza Ali
May 17, 2023
REQUIREMENTS

Your program should behave exactly like the Unix shell in terms of output and error messages, including any formatting or syntax. This ensures that your program is consistent with the behaviour of other Unix utilities and can be seamlessly integrated with other Unix tools in a command-line environment.

    To meet this requirement, you should carefully test your program to ensure that it produces the same output and error messages as the Unix shell in different scenarios and with different inputs. You may also need to consult the documentation for /bin/sh to understand its behavior and ensure that your program is in compliance with its specifications.

The PATH is an environment variable on Unix-like operating systems, DOS, OS/2, and Microsoft Windows, specifying a set of directories where executable programs are located.

When you type a command into your terminal, the system will look for that command in the directories listed in the PATH. If the command is found in one of these directories, the system will execute it.

Here's an example of what the PATH might look like:

usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

This is a colon-separated list of directories. When you type a command, the system will look for that command in each of these directories, in order, until it finds it.

    You can see the current value of your PATH by typing echo $PATH in your terminal.

/bin/bash is the path to the Bash shell interpreter on Unix-based operating systems. Bash is a commonly used shell on Unix and Linux systems, and it provides a command-line interface for interacting with the operating system.

When you execute a Bash script or type commands into a Bash shell, the /bin/bash program is responsible for interpreting and executing those commands.

COMPILATION

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

The various options used in this command are:

-Wall: Enables all warning messages during compilation to help catch potential errors.

-Werror: Treats all warnings as errors, causing the compilation to fail if any warnings are generated.

-Wextra: Enables additional warning messages that are not included with -Wall.

-pedantic: Enforces strict adherence to the ANSI C standard.

-std=gnu89: Specifies the version of the C standard to use during compilation. In this case, it specifies the GNU C89 standard.
Interactive Mode:

The "interactive" mode of a shell project refers to the way it behaves when it's run in an interactive environment, such as a terminal or command prompt. The default behavior of an interactive shell project can vary depending on the specific shell you're using.

Here's a simple example of how an interactive shell might work:

$ echo "Hello, World!"
Hello, World!

In this example, the shell is waiting for user input. When the user types echo "Hello, World!" and hits Enter, the shell executes the command and then displays the output (Hello, World!) and then waits for more input.

Here's another example

$ ls
file1.txt  file2.txt  file3.txt

In this example, the ls command is used to list the files in the current directory. The output is then displayed by the shell and the shell waits for more input.
Non - Interactive Mode

The default behavior of an interactive shell is to display the output of commands and then wait for more input. This is often referred to as a "read-eval-print loop" (REPL), as it reads the user's input, evaluates it (i.e., runs the command), prints the result, and then starts over.

Sure, here are a few more examples of non-interactive shell scripts:

    Script with multiple commands

#!/bin/bash
echo "Starting script..."
ls
echo "Script finished."

In this script, the shell reads the commands from the file and executes them one after another, without waiting for user input. The output of the script would be:

Starting script...
file1.txt  file2.txt  file3.txt
Script finished.

ِSimple example of a main function in C that opens a prompt to the user:

In this code, the `main` function enters an infinite loop where it prints a prompt (`>`) and then waits for the user to enter a command.

    The `fgets` function reads a line of input from the user and stores it in the `command` array.

Single-Word command line Shell:

Chart

A single-word command line in a shell is a command that is executed immediately when the user presses Enter. For example, if you're using a Unix-like shell, you might type ls and then press Enter. This would execute the ls command, which lists the files in the current directory.

Here's a breakdown of what each part does:

1. **Include Statements:**

- `#include <stdio.h>`: This includes the standard input/output library in C, which provides functions for input/output operations (like `printf` and `fgets`).

- `#include <stdlib.h>`: This includes the standard library in C, which provides general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.

- `#include <string.h>`: This includes the string library in C, which provides functions for manipulating arrays of characters (like `strchr` and `strcspn`).

- `#include <unistd.h>`: This includes the unix standard library, which provides access to the POSIX operating system API, including the `execve` function.

2. **Main Function:**

- `char command[100];`: This declares a character array to store the command entered by the user.

- `char *argv[2];`: This declares an array of pointers to character strings. It will be used to pass the command and its arguments to the `execve` function.

- `char *envp[] = { NULL };`: This declares an array of pointers to environment variables. In this case, it's set to NULL, meaning no environment variables are passed to the `execve` function.

- `int status;`: This declares an integer to store the status returned by the `execve` function.

3. **While Loop:**

- The `while(1)` loop creates an infinite loop, which is typical for a shell program because it needs to continuously accept and execute commands until it's explicitly exited.

- `printf("> ");`: This prints the shell prompt.

- `fgets(command, sizeof(command), stdin);`: This reads a line of input from the user and stores it in the `command` array.

- `command[strcspn(command, "\n")] = 0;`: This replaces the newline character at the end of the input with a null character. `strcspn` returns the length of the initial segment of `command` which consists entirely of characters not in `"\n"`.

4. **Command Execution:**

- The `if` statement checks if the command is a single-word command (i.e., it doesn't contain any spaces). If it is, it sets `argv[0]` to the command and `argv[1]` to NULL, and then calls `execve` to execute the command.

- `status = execve(command, argv, envp);`: This tries to execute the command. `execve` replaces the current process image with a new process image specified by `command`. It also passes `argv` (an array of argument strings) and `envp` (an array of environment strings) to the new process image.

- If `execve` returns -1, it means there was an error executing the command. The `perror` function is then called to print a descriptive error message to the standard error stream.

- If the command is not a single-word command, the program prints a message saying it's not a single-word command.

5. **Return Statement:**

- `return (0);`: This returns 0 from the `main` function, which signifies that the program has executed successfully. In this case, this line will never actually be reached because of the infinite loop. The program can only be exited by sending it a signal (like pressing Ctrl+C).

In the context of a simple shell, environmental variables play a vital role in determining the behavior and configuration of the shell and the processes it spawns. Here's how environmental variables are relevant to a simple shell:

Path Information: The PATH environmental variable is particularly crucial for a shell. It contains a list of directories where the shell should look for executable files. When a user enters a command, the shell checks these directories for the corresponding executable to run.
What about command lines with arguments ?

    In a shell program, a command line with argument refers to a command that includes one or more additional words or values that are passed as arguments to the command. For example, in the command ls -l or cat myfile.txt. for example

In contrast, a command line without arguments refers to a command that does not take any additional words or values. For example, the pwd command simply displays the current working directory and does not take any arguments.

    To handle command lines with arguments in a shell program, you can follow these general steps:

        Read the input from the user using a function like getline.

        Parse the input to separate the command from its arguments. This can be done using a tokenizer function like strtok, which can split the input string into tokens based on a delimiter, such as whitespace.

        Determine the command to execute based on the first token in the input string.

        Pass the remaining tokens as arguments to the command. This can be done by constructing an array of strings that contains the command and its arguments, and passing this array to the execve.

        Execute the command with the specified arguments. This can be done using the execve, which can execute a command with a set of arguments.

By following these steps, you can handle command lines with arguments in your shell program, allowing users to customize the behaviour of commands and make the program more flexible and powerful.

Example Snippet in C:

Consider:

    a child process is created to execute the command provided by the user. The reason for creating a child process instead of executing the command in the parent process is to ensure that the shell remains active and responsive to the user.

Here's a more detailed explanation:

    Isolation: When a new process is created using fork(), it becomes a separate execution entity with its own memory space. This means that if the command being executed crashes or has a bug that causes it to behave unexpectedly, it won't affect the parent process (i.e., the shell). This isolation helps to maintain the stability and reliability of the shell.

    Concurrency: By creating a child process to execute the command, the parent process (i.e., the shell) can continue to accept and process new commands from the user while the child process is still running. This allows for concurrent execution of commands, which can improve the responsiveness and efficiency of the shell.

Child Process:

    If pid is 0, it means we're in the child process. The child process then tries to execute the command using execvp.

    execvp(args[0], args);: This replaces the current process image with a new process image specified by args[0]. It also passes args (an array of argument strings) to the new process image. The first argument to execvp is the name of the program to be executed, and the second argument is an array of strings representing the arguments to the program.

    If execvp fails, it returns -1. The program checks for this and calls perror to print an error message, and then exits with a failure status.

Handle env :

env built-in command that prints the current environment in C, you can use the environ variable, which is a global variable that holds all the environment variables. The environ variable is an array of strings, where each string is an environment variable in the form name=value.

ERROR HANDLING in command line with arguments:

When handling command lines with arguments in a shell program, there are several possible errors that can occur that need to be handled gracefully. Here are some examples:

    Invalid input: The user may enter invalid input, such as a command that is not recognized by the shell program or a command with incorrect arguments. In this case, the shell program should display an error message to the user and prompt for new input.

    Memory allocation errors: If the shell program is using dynamic memory allocation to parse and process input, it may encounter memory allocation errors if there is not enough memory available to allocate the required resources. In this case, the shell program should display an error message and terminate gracefully.

    File I/O errors: If the shell program is reading input from a file or writing output to a file, it may encounter file I/O errors if there are problems with the file system or if the file is not accessible. In this case, the shell program should display an error message and terminate gracefully.

    Command execution err

    ors: When executing a command with arguments, there may be errors that occur during the execution of the command, such as invalid arguments or a failure to access required files or resources. In this case, the shell program should display an error message to the user and return control to the shell prompt.

    Interrupts: The user may interrupt the shell program by pressing a key combination such as Ctrl+C or Ctrl+D. In this case, the shell program should handle the interrupt gracefully and terminate any ongoing processes or operations.
    Once the argument array is constructed with malloc(), the execve() function is called to execute the command with the specified arguments. The fork function is used to create a child process to execute the command, while the parent process waits for the child process to complete using the wait function.

    Once the argument array is constructed with malloc(), the execve() function is called to execute the command with the specified arguments. The fork function is used to create a child process to execute the command, while the parent process waits for the child process to complete using the wait function.

Sure, If the execve function encounters an error, the shell program displays an error message to the user and exits with a failure status.

By constructing an array of strings containing the command and its arguments, the shell program can pass any number of arguments to a command and provide greater flexibility and customization options to the user.
NON-INTERACTIVE MOOD

    Handling non-interactive mode in a shell program typically involves reading commands from a file, script, or another command

    After mood check mode with isatty() function, if the mode in non interactive, this means that commands are going to be read from a file, the open function is used to open the file specified by the second command-line argument in read-only mode. The read function is used to read data from the file into a buffer, which can then be processed in the same wayas if it were read using fgets. The close function is used to close the file descriptor when the file has been fully read.

    Note that the read function returns the number of bytes read, which can be less than the size of the buffer if the end of the file is reached before the buffer is filled. The while loop in the example continues reading from the file until no more bytes can be read.

To process the buffer and execute commands in a file, you can follow these steps:

    Parse the buffer into individual lines using a delimiter like the newline character (\n).

    For each line, parse the line into separate command-line arguments using a function like strtok.

    Execute each command using a function like execve

    non interactive mood in simple shell diagram

    the open function is used to open the file specified by the second command-line argument in read-only mode. The read function is used to read data from the file into a buffer, which can then be processed in the same wayas if it were read using fgets. The close function is used to close the file descriptor when the file has been fully read.

    the open function is used to open the file specified by the second command-line argument in read-only mode. The read function is used to read data from the file into a buffer, which can then be processed in the same way as if it were read using fgets. The close function is used to close the file descriptor when the file has been fully read.

        Note that execve is a system call that replaces the current process image with a new process image specified by the path argument. In this case, args[0] is the path to the executable file, and args is an array of strings containing the command-line arguments for the new process.

        execve(args[0], args, NULL)

HANDLE PIPES

    Handling pipes in a shell program written in C involves creating a pipeline between two processes, where the output of one process is used as the input for the next process 

Pipes in a shell are used to redirect the output of one command to the input of another command. They are represented by the | character.

Here's a simple example of how to use pipes in a shell:

$ ls -l | grep ".txt"
$ cat myfile.txt | wc -l

    In this example, ls -l lists all files in the current directory in long format, and grep ".txt" filters the output of ls -l to only show lines that contain ".txt". The output of ls -l is piped to grep ".txt".

Notes:

The handle_pipe function you provided seems to be part of a shell program written in C that handles pipes. Let me break down the function for you:

    The function takes a string input as its parameter, which represents a command line containing a pipe (|) to connect two commands.

    It uses strtok to split the input into two commands (command1 and command2) based on the pipe character.

    If there is no pipe in the input (meaning command2 is NULL), it means there is only one command, so it directly executes that command using the execute_command function.

    If there is a pipe, it creates a pipe using the pipe system call.

    It forks a child process using fork. In the child process, it closes the unused read end of the pipe (pipefd[0]), redirects its standard output to the write end of the pipe (pipefd[1]), and then executes the first command (command1).

    In the parent process, it closes the unused write end of the pipe (pipefd[1]), redirects its standard input from the read end of the pipe (pipefd[0]), and then executes the second command (command2).

This way, the output of command1 becomes the input of command2, simulating the behavior of a pipe in a shell.

So in summary, when receiving input from a pipe for a non-interactive shell, you read the entire input, execute one command, and then exit. Whereas an interactive shell reads input line by line in a loop.

    Remember : In the context of the shell program, active and non-active modes refer to the way in which commands are read and executed.

    In interactive mode, the shell reads commands from the user in real-time and executes them immediately. The user inputs a command, and the shell executes it and provides a new prompt for the user to enter another command.

    In non-interactive mode, the shell reads commands from a file or stream, rather than from the user in real-time. The commands are read and executed in batch mode, without any user interaction. The example : the commands are read from a file or from an echo command piped into the shell program. The shell executes each command in the file or stream and provides the output accordingly. 

Free and avoid leaks:

    In C, several functions allocate memory dynamically and return a pointer to the allocated memory. This memory should be freed when it's no longer needed to prevent memory leaks. Here are some of these functions:

    strdup(): Duplicates a string by allocating memory for the duplicate and copying the original into it.

    strndup(): Similar to strdup(), but only duplicates the first n characters of the string.

    getline(): Reads a line from a file (or other input stream) and allocates enough memory to hold the line.

Check Leaks Source:

If you suspect that your C program has memory leaks, you can use a tool called a memory profiler or leak detector to help identify the sources of the leaks. One such tool is Valgrind.

Valgrind is a powerful tool that can detect memory leaks and other issues like use of uninitialized memory, reading/writing of memory after it has been free'd, reading/writing off the end of malloc'd blocks, and reading/writing inappropriate areas on the stack.

Here's how you might use Valgrind to check for memory leaks:

    Install Valgrind. On a Debian-based Linux system, you can do this with sudo apt-get install valgrind.

    Compile your program with debugging information. If you're using gcc, you can do this with the -g option: gcc -g myprogram.c -o myprogram.

    Run your program under Valgrind with the --leak-check=full option: valgrind --leak-check=full ./myprogram.
    Example:

Thank you for reading Shaza’s Substack. This post is public so feel free to share it.

Share

Resources:

Guide to code a simple shell in C | by Winfred Kilonzo | Medium

Tutorial to code a simple shell for beginners in C | The Startup - Medium

Tutorial - Write a Shell in C • Stephen Brennan

Github Snippets
Simple Shell
How to Run Linux on Windows: WSL, Ubuntu, and VS Code
Shaza Ali
·
July 2, 2023
How to Run Linux on Windows: WSL, Ubuntu, and VS Code

Using WSL, Ubuntu, and VS Code together is a popular setup for Windows users who want to develop software in a Linux environment. Here are the basic steps to get started: Install WSL: Follow the instructions provided by Microsoft here: https://docs.microsoft.com/en-us/windows/wsl/install-win10
Read full story
Test Cases:

https://simple-shell-tests.vercel.app/
Subscribe to Shaza’s Substack

Launched 9 months ago

My Tech Substack
8 Likes
5 Comments
	
Shymaa Ismail
Oct 4, 2023

Thanks alot shaza for this comprehensive well descriptive article
Like
Reply
Share
1 reply by Shaza Ali
	
bitplayer
Writes Journeys Within
Nov 16, 2023
Liked by Shaza Ali

This is brilliant
Like (1)
Reply
Share
2 replies by Shaza Ali
3 more comments...
Top
New
Community
"Creating Your Own Command Interpreter: Main Concepts Guide: Simple Shell - Part 1"
Deeper into UNIX: Exploring the Inner Workings of UNIX with a Custom Interpreter
May 7, 2023
 • 
Shaza Ali
19
5
"Monty: Stacks on Stacks: A LIFO & FIFO Love Story PART 2"
ALXSE oriented guide - 0x19. C - Stacks, Queues - LIFO, FIFO - Monty 1st.
Jun 21, 2023
 • 
Shaza Ali
4
Airbnb Clone Console (PREP)!
Serialization Deserialization - *args and **kwargs - File Storage - cmd
Aug 5, 2023
 • 
Shaza Ali
7
2

Ready for more?
© 2024 Shaza Ali
Privacy ∙ Terms ∙ Collection notice
Start Writing
Get the app
Substack is the home for great writing
