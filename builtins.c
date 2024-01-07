#include "shell.h"

int ss_help( __attribute__((unused)) char **args) {
    char *helptext =
        "Kash - the Kinda Aimless Shell. "
        "The following commands are available:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n";
    printf("%s", helptext);
    return (1);
}

int ss_exit(__attribute__((unused)) char **args) {
    exit(0);
}

int ss_env(char **args)
{
    if (strcmp(args[0], "env") == 0)
    {
        char **env = environ;
        while (*env != NULL)
        {
            printf("%s\n", *env);
            env++;
        }
    }
    return(1);
}
