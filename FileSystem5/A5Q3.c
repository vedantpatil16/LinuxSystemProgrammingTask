#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    char namecopy[30] = {'\0'};
    int ret = 0;
    struct FileInfo fobj;
    struct stat sobj;
    int fd = 0;

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
        sprintf(name,"%s/%s",DirName,entry->d_name);
        if((entry->d_type) == DT_REG)
        {
            stat(name,&sobj);
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
        }
    }

    fd = open("AllCombine.txt",O_RDONLY);

    while(ret = (read(fd,&fobj,sizeof(fobj))) != 0)
    {
        printf("File name is : %s\n",fobj.FileName);
        printf("File size is : %d\n",fobj.FileSize);
    }


    closedir(dp);
    
    return 0;
}
