#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char FileName[20];

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("Enter name of file :\n");
    scanf("%s",FileName);

    while((entry = readdir(dp)) != NULL)
    {
        if(strcmp(FileName,entry->d_name)== 0)
        {
            break;
        }
    }

    if(entry != NULL)
    {
        printf("%s is present in the directory\n",FileName);
    }
    else
    {
        printf("%s is not present in the directory\n",FileName);
    }

    closedir(dp);

    return 0;
}
