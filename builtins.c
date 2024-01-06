#include "main.h"
 int SS_BUILTINS = (sizeof(builtins) / sizeof(char *));

void ss_help( __attribute__((unused)) char **args) {
    int i;
    char *helptext =
        "Kash - the Kinda Aimless Shell. "
        "The following commands are available:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n";
    printf("%s", helptext);

    for (i = 0; i < SS_BUILTINS; i++)
    {
        printf("%s\n", builtins[i]);
    }

    return (1);
}

void ss_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "kash: cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("kash: cd");
        }
    }
}

void ss_exit(__attribute__((unused)) char **args) {
    exit(0);
}

void ss_env(char **args)
{
    if (strcmp(args[0], "env") == 0)
    {
        char **env = environ;
        while (*env != NULL)
        {
            printf("%s\n", *env);
            env++;
        }
        return;
    }
}
