/* Lab 1: write a program to search a directory and print the contents (just like -ls) */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

int main (int argc, char *argv[])
{
	int fd;
	DIR *wd;
	struct dirent *entry;
	struct stat st;

	if (argc < 2) 
	{
		printf("\n No folder specified. \n");
		return -1;
	}

	fd = open (argv[1], O_RDONLY | O_DIRECTORY, 00444);

	if (fd == -1)
	{
		perror("\n Error opening %s : ");
		return -1;
	}

	wd = fdopendir(fd);

	if (wd == NULL) 
	{
		perror("\n Opening directory failed: \n");
		return -1;
	}

	while ((entry = readdir (wd)) != NULL)
	{
		printf("\n-> %6s", entry->d_name);
		if (stat (entry->d_name, &st) == -1)
		{
			perror("\n  !!! ");
		//	break;
		}
		else
		{			
			printf("\n    -      inode = %x",(int) st.st_ino);
			printf("\n    - protection = %o", st.st_mode);
			printf("\n    -      owner = %d", st.st_uid);
			printf("\n    -       size = %d",(int) st.st_size);
		}
	}
	
        close(fd);
	perror("\n");
	return 0;
}



