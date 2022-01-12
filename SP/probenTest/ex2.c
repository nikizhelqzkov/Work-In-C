// Задача 2. В текущия каталог се намира текстов файл abc
//със следното съдържание : Let’s go change the world !

// Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход
// като резултат от изпълнението на дадения по -
//долу фрагмент от програма на С :
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
//Let’s go change the world!
//Let|’s go change the world!
//Let’s go ||change the world!
int main()
{
    int fdi, fdio, nb1, nb2;
    char buf[15];
    fdi = open("abc", O_RDONLY); //only read
    fdio = open("abc", O_RDWR); //for both

    nb1 = read(fdi, buf, 6); //Let’s_
    write(1, buf, nb1);//Let’s_

    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buf, 6);
    write(1, buf, nb1);//change

    lseek(fdio, -18, SEEK_END);
    write(fdio, "tra", 3);
    //Let’s go ||travel the world!
    write(fdio, "vel", 3);
    nb2 = read(fdio, buf, 5);//_the_ 
    write(1, buf, nb2);//_the_ 
    write(1, "time", 4);//time

    lseek(fdi, -2, SEEK_END);
    //Let’s go ||travel the world!
    nb2 = read(fdi, buf, 2);
    write(1, buf, nb2);//d!
}
//output:Let’s_change_the_timed!
//file:Let’s go ||travel the world!