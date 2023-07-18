#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    char Buffer[BLOCKSIZE] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    char name[30];
    int ret = 0;
    int fd = 0, fdread = 0;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("AllCombine.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        if((entry->d_type) == DT_REG)
        {
            sprintf(name,"%s/%s",DirName,entry->d_name);
            stat(name,&sobj);
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            fdread = open(name, O_RDONLY);
            while((ret = read(fdread,Buffer,BLOCKSIZE)) != 0)
            {
                write(fd,Buffer,ret);
            }
            close(fdread);
        }
    }

    close(fd);
    closedir(dp);
    
    return 0;
}
