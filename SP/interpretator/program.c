#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    char *text = (char *)malloc(sizeof(char) * 1000);
    // char text[100];
    char *buf = (char *)malloc(sizeof(char) * 1);
    char **args = (char **)malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++)//na vsqko nuzhno samo da go pravq
    {
        args[i] = (char *)malloc(100 * sizeof(char));
    }
    write(1, "Hello to the command prompt\nWrite your commands\n", 48);
    while (strcmp(text, "logout") != 0 && strcmp(text, "bye") != 0 && strcmp(text, "quit") != 0)
    {
        write(1,"nikizhelqzkov@interpretator> ",30);
        free(text);
        text = (char *)malloc(sizeof(char) * 1000);
        int size = 0;
        int c;
        int isEndOfLine = 0;
        int lastIndex = 0;
        int curArg = 0;
        while ((isEndOfLine == 0))
        {
            c = (read(0, buf, 1)) > 0;
            if (buf[0] == '\n')
            {
                if (strcmp(text, "logout") == 0 || strcmp(text, "bye") == 0 || strcmp(text, "quit") == 0)
                {
                    break;
                }
                buf[0] = '\0';
                text[lastIndex] = buf[0];
                isEndOfLine++;
                strcpy(args[curArg], text);
                ++curArg;
                // write(1, "f", 1);
                //exec
                int pid = fork();
                int status = 0;
                if (pid > 0)
                {
                    wait(&status);
                }
                else if (pid == 0)
                {

                    // args[curArg + 1] = NULL;
                    // printf("%s",args[1]);
                    args[curArg] = NULL;
                    // exit(0);
                    if (execvp(args[0], args) == -1)
                    {
                        write(1, "Error command\n", 15);
                    }
                }
            }
            else if (buf[0] == ' ')
            {
                if (strlen(text) == 0)
                {
                    continue;
                }
                text[lastIndex] = '\0';
                // for (int i = 0; i <= lastIndex; i++)
                // {
                //     args[curArg][0] = text[i];
                // }
                strcpy(args[curArg], text);
                // args[curArg] = text;
                //    write(1,args[curArg])
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
    return 0;
}