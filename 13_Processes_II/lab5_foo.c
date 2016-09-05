/* lab5: exiting, constructor & destructors */

#define _GNU_SOURCE

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

void init_fun (void) __attribute__ ((constructor));
void exit_fun (void) __attribute__ ((destructor));

void init_fun (void)
{
	printf("\n ---- Constructor ---- \n");
}

void exit_fun (void)
{
	printf("\n ---- Destructor ---- \n");
}

void somefun1 (void)
{
	printf("\n somefun1() printed this.\n");
}

void somefun2 (void)
{
	printf("\n somefun2() printed this. \n");
}

int main (int argc, char * argv[])
{
	printf("\n Main() started.\n");

	if (atexit(somefun1) < 0)
	{
		perror("atexit");
		exit(errno);
	}
	printf("\n Installed somefun1() \n");

	if (atexit(somefun2) < 0)
	{
		perror("atexit");
		exit(errno);
	}
	printf("\n Installed somefun2() \n");
	
	exit(EXIT_SUCCESS);
}

