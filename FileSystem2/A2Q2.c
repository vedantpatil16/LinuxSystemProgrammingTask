#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Str[11] = "Hello World";

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open((argv[1]),O_WRONLY | O_APPEND);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    write(fd,Str,sizeof(Str));

    close(fd);


    return 0;
}
