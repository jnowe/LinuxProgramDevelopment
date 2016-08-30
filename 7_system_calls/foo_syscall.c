
#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>

int main (int argc, char *argv[])
{
	int pid = 0;
	pid = syscall(SYS_getpid);
	printf("Process ID = %d\n", pid);
	return 0;
}
