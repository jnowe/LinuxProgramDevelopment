/* Lab 1: write a program to search a directory and print the contents (just like -ls) 
 * Update the program so that for every subdirectory found, it forks a child to process it. */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
	// 1. check argument
	// * 2. open as directory - open()
	// * 3. open directory - fdopendir()
	// * 4. read dir entries until the end (skip . and ..)
	// * 5. if entry is a dir fork a child and run from pt 2.
	// * 6. if not a dir, display file information

#define DEATH(cmd) \
{perror(cmd); return (-1);}

int analyzedir (char *dirname)
{
	int fd;
	DIR *wd;
	struct dirent *entry;
	struct stat st;
	pid_t mypid;
	char *path;

	fd = open(dirname, O_RDONLY | O_DIRECTORY, 00444);
	if (fd == -1) DEATH("\n Error opening dir:");
	printf("\n[%d]  <%s> Directory:", getpid(), dirname);

	wd = fdopendir(fd);
	if (wd == NULL) DEATH("\n Failed opening dir:");

	while ((entry = readdir(wd)) != NULL)
	{
		path = calloc(1,strlen(dirname)+strlen(entry->d_name)+1);
		path = strcat(path, dirname);
		path = strcat(path, "/");
		path = strcat(path, entry->d_name);
		if (stat(path, &st) == -1) 
		{
			perror("\n stat() failed:");
			break;
		}
		else if (S_ISDIR(st.st_mode))
		{
			if ((strcmp(".", entry->d_name) == 0) || \
					(strcmp("..", entry->d_name) == 0)) 
			{
				//printf("\n[%d]   [%s] ignored.", getpid(), path);
				//fflush(stdout);
			}
			else if ((mypid = fork()) == 0) 
			{
				//printf("\n --- Process %d initiated ---", getpid());
				fflush(stdout);
				analyzedir(path);
				return 0;
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			printf("\n[%d]    -> %6s \n", getpid(), entry->d_name);
			/*printf("\n               inode = %x",(int) st.st_ino);
			printf("\n          protection = %o", st.st_mode);
			printf("\n               owner = %d", st.st_uid);
			printf("\n                size = %d",(int) st.st_size);*/
			fflush(stdout);
		}
		free(path);
	}
	close(fd);
}
int main (int argc, char *argv[])
{
	if (argc < 2) 
	{
		printf("\n No folder specified. \n");
		return -1;
	}

	analyzedir(argv[1]);
	
	//printf("\n --- Process %d finished ---", getpid());
	return 0;
}



