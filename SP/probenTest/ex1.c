#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
// ptr
// Задача 1  Да се напише програма на Cи, която получава при стартиране следните параметри:  име на файл и команда с опции и аргументи.
// Използвайки системните примитиви за работа с файлове и процеси в Linux:
//     • копира файла, подаден като първи позиционен параметър във файла f1, в директория  /home/student чрез команда cp
//     • изпълнява команда, извеждаща списък на файловете от директория /home/KN/SYSPROG, с показани права на достъп
//     • изпълнява командата с опции и аргументи подадена като параметър и при успешно изпълнение на последната извежда номерата на трите процеса,
//  изпълняващи командите.

int main(int argc, char **argv)
{
    int status1, status2, status3;
    int pr1, pr2, pr3;
    char **buf = (char **)malloc((argc) * sizeof(char));
    for (int i = 2; i < argc; i++)
    {
        buf[i - 2] = argv[i];
    }
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        execlp("cp", "cp", argv[1], "../trasirovki/ex1.c", (char *)0); /// home/student
    }
    else if (pid1 > 0)
    {
        pr1 = wait(&status1);
    }
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        execlp("ls", "ls", "-l", "../trasirovki/", (char *)0); //  /home/KN/SYSPROG
    }
    else if (pid2 > 0)
    {
        pr2 = wait(&status2);
    }
    pid_t pid3 = fork();
    if (pid3 == 0)
    {
        execvp(argv[2], buf);
    }
    else if (pid3 > 0)
    {
        pr3 = wait(&status3);
        if (status3 == 0)
        {
            printf("%d ; %d ; %d\n", pr1, pr2, pr3);
        }
    }
    return 0;
}