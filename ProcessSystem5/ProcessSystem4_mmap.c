#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *addr;
    int fd = 0;

    struct stat sb;
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("%s filename\n",argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    if (fstat(fd, &sb) == -1)
    {
        printf("Unable to fetch size of the file\n");
        return -1;
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
    {
        printf("Unable to map the file");
    }

    write(1,addr,sb.st_size);

    if(munmap(addr,sb.st_size) == -1)
    {
        printf("Failed to unmap file\n");
    }
    else
    {
        printf("File unmapped successfully\n");
    }

    return 0;
}
