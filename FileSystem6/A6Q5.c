#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int Ret = 0;

    if(argc!=3)
    {
        printf("Insuffient Arguments\n");
        printf("Usage : ./Executable_Name   Name_Of_File  Offset\n");
        return -1;
    }

    truncate(argv[1],atoi(argv[2]));


    return 0;
}
