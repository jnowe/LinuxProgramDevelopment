/* simple usage of system call system() - send the command to a shell and returns the result */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	printf("\n Status of <echo> command is %d \n", system("echo it worked !!!"));
	return 0;

}
