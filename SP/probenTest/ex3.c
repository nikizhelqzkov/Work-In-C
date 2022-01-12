#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
Zадача 3 Като първи параметър на програма на С се подава съществуващ празен файл. 
Напишете какво ще има записано във файла и какво ще бъде изведено
 на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С :
*/
int main(int argc, char *argv[])
{
    int fd, i, status;
    if (fork())
    {
        wait(&status);
        for (i = 0; i <= 3; i++)
        {
            write(1, "cal\n", 4);//output cal
            execlp("cal", "cal", 0);//calendat
            write(1, "hello1\n", 6);
        }
    }
    else
    {
        close(1);
        fd = open(argv[1], O_RDWR);
        write(1, "hello2\n", 6);//in file write hello2
    }
    write(1, "hello3\n", 6); //hello3 in file
}
//output:
//cal
//calendar
/*\
file:hello2
hello3
*/
