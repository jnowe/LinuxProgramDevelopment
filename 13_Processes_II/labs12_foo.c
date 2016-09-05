/* simple usage of system call system() - send the command to a shell and returns the result */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#define OBSERVE_ZOMBIEKILLER 1

int main(int argc, char *argv[])
{
	pid_t mypid;

	if ((mypid = fork()) == 0)
	{
		printf("\n Child process ! \n");
		printf("\n PID      = %d \n Parent PID = %d \n Group PID = %d \n", getpid(), getppid(), getpgid(getpid()));
		if (OBSERVE_ZOMBIEKILLER) sleep(10);
	}
	else if (mypid > 0)
	{
		printf("\n Parent process ! \n");
		printf("\n PID      = %d \n Parent PID = %d \n Group PID = %d \n", getpid(), getppid(), getpgid(getpid()));
	}
	else
	{
		perror("\n Fork() failed ");
	}
 
	printf("i\n Process %d finished !", getpid());
	return 0;

}
