Simple Shell

Simple Shell is a UNIX command line interpreter developed as part of the Holberton School curriculum. It provides a basic shell environment for users to interact with the operating system. The Simple Shell supports various features such as executing commands, process management, environment manipulation, and built-in commands.
Getting Started

To compile the Simple Shell, run the following command:

gcc -Wall -Werror -Wextra -pedantic *.c -o shell

To run the Simple Shell, execute the compiled binary:

./shell

Usage

Once the Simple Shell is running, it will display a prompt to wait for user input. The prompt is displayed as follows:

$ 

The user can then type a command line and press Enter to execute the command. The Simple Shell supports simple command lines consisting of a single word without any arguments. If the command exists and is executable, it will be executed. If the command does not exist, an error message will be displayed, and the prompt will appear again.

The Simple Shell supports the following built-in commands:

    exit: Exits the shell.
        Usage: exit

    env: Prints the current environment variables.
        Usage: env

Features

    Command execution: The Simple Shell can execute commands entered by the user.
    Process management: The Simple Shell manages processes using system calls like fork() and execve().
    Environment manipulation: The Simple Shell supports environment variable manipulation using functions like getenv(), setenv(), and unsetenv().
    Built-in commands: The Simple Shell provides built-in commands like exit and env.
    Error handling: The Simple Shell handles errors and displays appropriate error messages.

Limitations

The Simple Shell has the following limitations:

    No support for advanced features: The Simple Shell does not support advanced features like semicolons, pipes, redirections, or special characters.
    Single-word commands: The Simple Shell only supports command lines consisting of a single word without any arguments.
    Limited built-in commands: The Simple Shell only provides built-in commands for exit and env.
    No PATH resolution: The Simple Shell does not use the PATH environment variable to locate executables. Commands must be specified with their full path.

Authors

The Simple Shell was implemented by Kha1id Ashour and Omar Shalan as part of the Holberton School curriculum.
License

This project is licensed under the MIT License - see the LICENSE file for details.