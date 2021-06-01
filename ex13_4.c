#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char **args = (char **)malloc((argc + 1) * sizeof(char));
    for (int i = 1; i < argc; ++i)
    {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL;
    int pid = fork();
    int status = 0;
    if (pid == -1)
    {
        perror("Bad fork");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(&status);
        int fd = open("zone.txt", O_RDONLY);
        char *text = (char *)malloc(sizeof(char) * 15);
        read(fd, text, 10);
        close(fd);
        remove("zone.txt");
        printf("Children pid : %s, current pid:  %d ,  Status code: %d: \n", text, getpid(), status);
    }
    else
    {
        int fd = open("zone.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
        char *text = (char *)malloc(sizeof(char) * 15);
        sprintf(text, "%d", getpid());
        write(fd, text, 4);

        close(fd);
        exit(execvp(argv[1], args));
    }
    return 0;
}