#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char DirName[255] = {'\0'};

    printf("Enter the directory name to open\n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("Name of files are :\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }

    closedir(dp);

    return 0;
}
