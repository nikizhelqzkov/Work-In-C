#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd, k, nb;
    char buf[6];

    k = dup(0);//pazim potoka za chetene
    fd = open("fileB", O_RDWR);//otvarqme fileB za chetene i pisane
    nb = read(k, buf, 5); //buf = this_
    write(fd, buf, nb);//this_ vmesto It is
    lseek(fd, 1, SEEK_CUR);//preskacha _
    nb = read(fd, buf, 7); //buf = a nice_
    write(1, buf, nb);
    nb = read(0, buf, 4);//buf = this NE----->// buf = girl | zashtoto k e stignal do 4ti bait i fd=0 produlzhava ako ima nedocheteno
    write(1, buf, nb);
    close(fd);
    close(k);
    write(1, "\n", 1);
    execlp("cat", "cat", "fileB", 0);
}

// fileB - It is a nice day !stdin - this girl
// fileB:  this  a nice day 

//console: a nice girl\n
//this  a nice day