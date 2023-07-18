#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

#define BYTES_TO_READ 20


int main(int argc, char *argv[])
{
    int fd = 0;
    char Arr[BYTES_TO_READ];
    int Ret=0;

    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        printf("unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    Ret=read(fd,Arr,sizeof(Arr));

    printf("Data from file is : \n");
    write(1,Arr,Ret);

    close(fd);
    
    return 0;
}
