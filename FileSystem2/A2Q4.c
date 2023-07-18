#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;


    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        printf("Name : %s\t",entry->d_name);
        if((entry->d_type)==DT_REG)
        {
            printf("Type : Regular\n");
        }

        if((entry->d_type)==DT_BLK)
        {
            printf("Type : Block Device\n");
        }

        if((entry->d_type)==DT_CHR)
        {
            printf("Type : Charecter Device\n");
        }

        if((entry->d_type)==DT_DIR)
        {
            printf("Type : Directory file\n");
        }

        if((entry->d_type)==DT_LNK)
        {
            printf("Type : Symbolic Link\n");
        }

        if((entry->d_type)==DT_SOCK)
        {
            printf("Type : Unix Socket\n");
        }

        if((entry->d_type)==DT_FIFO)
        {
            printf("Type : Named Pipe\n");
        }

        if((entry->d_type)==DT_UNKNOWN)
        {
            printf("Type : Unknown file type\n");
        }
    }

    closedir(dp);

    return 0;
}
