/* lab4: Cloning - create a master & slave threads and demonstrate shared memory */

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

#define SLAVE_STACK_SIZE 4096

unsigned long global = 0;
int globalcond = 1;

int SlaveDo (void *inc)
{
	int initval = 0;
	
	while (globalcond)	
	{
		printf("\n                              Slave[%d]: global var = %lu \n", getpid(), global);
		global = global + (*(int*) inc);
		initval = global;
		while (initval == global)
		{
			sleep(1);
			printf("\n                              .\n");
		}
	}
	return 0;
}


int main(int argc, char * argv[])
{
	void *SlaveStack;
	int i;
	int inc_amount = 10;
	
	SlaveStack = calloc(1, SLAVE_STACK_SIZE);
	clone (SlaveDo, \
		(void*) SlaveStack+SLAVE_STACK_SIZE-1, \
		CLONE_VM | CLONE_FS | CLONE_FILES, \
		&inc_amount);

	for (i=0; i<30; i++)
	{
		sleep(4);
		global++;
		printf("\n Master[%d]: global var = %lu \n", getpid(), global);
	}

	globalcond = 0;

	return 0;
}
