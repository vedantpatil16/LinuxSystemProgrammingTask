#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define HOLESIZE 1024
#define TRUNC_SIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    DIR *dp = NULL;
    struct stat sobj;
    struct dirent *entry = NULL;
    char newname[30];
    char DirName[20];
    char Buffer [HOLESIZE] = {'\0'};

    printf("Enter directory name :\n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(newname,"%s/%s",DirName,entry->d_name);
        stat(newname,&sobj);
        if((entry->d_type) == DT_REG)
        {
            if(sobj.st_size < 1024 )
            {
                fd = open(newname, O_RDONLY | O_WRONLY );
                lseek(fd,0,SEEK_END);
                write(fd,Buffer,sizeof(Buffer));
                close(fd);
            }
            else if(sobj.st_size > 1024)
            {
                truncate(newname,TRUNC_SIZE);
            }
        }

    }

    closedir(dp);

    return 0;
}
