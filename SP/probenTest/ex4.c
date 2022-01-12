#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
/*
Задача  4  Да се напише програма на C, която получава 2 параметъра – имена на файлове.
Стартира команда тръсеща срещането на низ pts,
като пренасочва стандартния й вход от първия файл,
а стандартния й изход и изхода й за грешки - във втория. Накрая извежда кода й на завършване на екрана.
*/
int main(int argc, char **argv)
{

    int pid = fork();
    if (pid < 0)
    {
        perror("Fork error");
        exit(-1);
    }
    else if (pid > 0)
    {
        int status;
        wait(&status);
        printf("%d", status);
    }
    else
    {
        int fd1 = open(argv[1], O_RDONLY);
        if (fd1 == -1)
        {
            printf("error with opening file\n");
            exit(-1);
        }
        int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd2 == -1)
        {
            printf("error with opening file fd2\n");
            exit(-1);
        }
        dup2(fd1, 0);
        dup2(fd2, 1);
        dup2(fd2, 2);
        close(fd1);
        close(fd2);
        if (execlp("grep", "grep", "ptr", (char *)0) == -1)
        {
            printf("error");
        }
    }

    return 0;
}