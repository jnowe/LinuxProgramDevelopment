/* Lab 2: write a program the memor maps a file */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define DEATH(msg) \
	do {perror(msg); return -1;} while (0)

int main (int argc, char *argv[])
{
	int fd;
	char *addr, *ptr;
	struct stat info;
	off_t offset, pa_offset;
	size_t length;
	ssize_t s;

	if (argc < 2) DEATH("no file specified"); 

	fd = open (argv[1], O_RDWR, 00777);

	if (fd == -1) DEATH("file open");

        if (fstat(fd, &info) == -1) DEATH("fstat");

	length = info.st_size;

	addr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (addr == MAP_FAILED) DEATH("mmap"); 
	
	ptr = addr;

	while (*ptr != NULL)
	{
		if ((*ptr >= 'a') && (*ptr <= 'z')) *ptr = *ptr - 32;
                ptr++;
	}


	if (!(munmap(addr, length))) DEATH("munmap");
	close(fd);
	perror("\n");
	return 0;
}



