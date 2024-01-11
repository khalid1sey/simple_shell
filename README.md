# Simple Shell

The Simple Shell is a basic UNIX command line interpreter that allows users to execute commands and interact with the operating system. It provides a simple and intuitive interface for running commands and performing basic shell operations.

This shell implementation is designed to meet the requirements specified in the project prompts and follows the guidelines of the Betty style checker.

## Features

The Simple Shell offers the following features:

- Display a prompt and wait for the user to enter a command.
- Execute simple command lines consisting of a single word.
- Handle command lines with arguments.
- Implement basic error handling for command execution.
- Handle the end-of-file condition (Ctrl+D).
- Support the `PATH` environment variable to locate executables.
- Implement the built-in `exit` command to exit the shell.
- Implement the built-in `env` command to print the current environment.

## Getting Started

### Requirements

- GCC (GNU Compiler Collection)
- Linux environment

### Compilation

To compile the Simple Shell, follow these steps:

1. Clone the repository:

$ git clone https://github.com/your-username/simple_shell.git


2. Navigate to the project directory:

$ cd simple_shell


3. Compile the source files.

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

This will generate an executable file named `hsh`.

### Usage

Once the compilation is successful, you can run the Simple Shell by executing the compiled binary:

$ ./shell
vim


The shell will display a prompt (`#cisfun$`) and wait for you to enter a command. Simply type a command and press Enter to execute it. After the command has been executed, the prompt will be displayed again, ready for the next command.

Here are a few examples of commands you can try:

```shell
#cisfun$ ls
file1  file2  file3
#cisfun$ echo Hello, world!
Hello, world!
#cisfun$ /bin/ls -l
total 8
-rwxrwxr-x 1 user user 8752 Jan 10 13:00 shell
#cisfun$ exit

To exit the shell, you can use the exit command or press Ctrl+D.
Project Structure

The repository consists of the following files:

    shell.c: The main entry point of the shell program.
    input_handling.c: Helper functions for tokenizing input, executing commands, and handling errors.
    shell.h: Header file containing function prototypes and macro definitions.
    builtins.c: Implementation of built-in commands (exit and env).


Limitations

Please note that this Simple Shell implementation has some limitations and does not support the following:

    Advanced shell features like pipes, redirections, and background processes.
    Handling of special characters such as quotes, backticks, and wildcards.
    Cursor movement and editing capabilities.

Contributors

This Simple Shell project was developed by Khalid sineayehu as part of a project for Alx Programme.

Contributions to the project are welcome. If you find any bugs or have suggestions for improvements, please feel free to open an issue or submit a pull request.