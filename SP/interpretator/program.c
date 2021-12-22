#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
int pipeExecuting(int size, char **argv, int pipePos)
{
    char **bufF = (char **)malloc((size) * sizeof(char));
    for (int i = 0; i < pipePos; i++)
    {
        bufF[i] = argv[i];
    }
    char **bufS = (char **)malloc((size) * sizeof(char));
    for (int i = pipePos + 1; i < size; i++)
    {
        bufS[i - pipePos - 1] = argv[i];
    }

    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid > 0)
    {
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        execvp(argv[0], bufF); // to be fixed
    }
    else if (pid == 0)
    {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        close(fd[0]);
        execvp(argv[pipePos + 1], bufS);
    }
}

int isHasPipeSymbol(char **args, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(args[i], "|") == 0)
        {
            return i;
        }
    }
    return -1;
}
void executeLine(int curArg, char **args)
{
    int pid = fork();
    int status = 0;
    if (pid > 0)
    {
        wait(&status);
    }
    else if (pid == 0)
    {
        // while it has "|" or i<n
        int pipePos = isHasPipeSymbol(args, curArg);
        if (pipePos > 0)
        {
            exit(pipeExecuting(curArg, args, pipePos));
        }
        else
        {
            args[curArg] = (char *)malloc(100 * sizeof(char));
            args[curArg] = NULL;
            if (execvp(args[0], args) == -1)
            {
                write(1, "Error command\n", 15);
                exit(0);
            }
        }
    }
}
void readText(int isEndOfLine, char *buf, char *text, char **args)
{
    int size = 0;
    int lastIndex = 0;
    int curArg = 0;
    while (isEndOfLine == 0)
    {
        if (strcmp(text, "logout") == 0 || strcmp(text, "bye") == 0 || strcmp(text, "quit") == 0)
        {
            exit(0);
        }
        read(0, buf, 1);
        if (buf[0] == '\n')
        {
            if (strcmp(text, "logout") == 0 || strcmp(text, "bye") == 0 || strcmp(text, "quit") == 0)
            {
                exit(0);
            }
            buf[0] = '\0';
            text[lastIndex] = buf[0];
            isEndOfLine++;
            args[curArg] = (char *)malloc(100 * sizeof(char));
            strcpy(args[curArg], text);
            ++curArg;
            executeLine(curArg, args);
        }
        else if (buf[0] == ' ')
        {
            if (strlen(text) == 0)
            {
                continue;
            }
            text[lastIndex] = '\0';
            args[curArg] = (char *)malloc(100 * sizeof(char));
            strcpy(args[curArg], text);
            ++curArg;
            free(text);
            text = (char *)malloc(sizeof(char) * 1000);
            lastIndex = 0;
        }
        else
        {
            text[lastIndex] = buf[0];
            ++lastIndex;
        }
    }
}
void interStart(char *text, char *buf, char **args)
{
    while (strcmp(text, "logout") != 0 && strcmp(text, "bye") != 0 && strcmp(text, "quit") != 0)
    {
        write(1, "nikizhelqzkov@interpretator> ", 30);
        free(text);
        text = (char *)malloc(sizeof(char) * 1000);
        int isEndOfLine = 0;
        readText(isEndOfLine, buf, text, args);
    }
}

int main()
{
    char *text = (char *)malloc(sizeof(char) * 1000);
    char *buf = (char *)malloc(sizeof(char) * 1);
    char **args = (char **)malloc(100 * sizeof(char *));
    write(1, "Hello to the command prompt\nWrite your commands\n", 48);
    interStart(text, buf, args);
    return 0;
}