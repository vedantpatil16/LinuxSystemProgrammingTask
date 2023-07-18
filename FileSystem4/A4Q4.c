#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

#define BYTES_TO_READ 10

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    int fd = 0, fdread = 0, ret = 0;
    char Buffer[BYTES_TO_READ];

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        if((entry->d_type) == DT_REG)
        {
            fdread = open(name,O_RDONLY);
            if(fdread == -1)
            {
                printf("Unable to open file\n");
                break;
            }
            ret = read(fdread,Buffer,sizeof(Buffer));
            write(fd,Buffer,ret);
            close(fdread);
        }
    }

    closedir(dp);
    
    return 0;
}
