/* create a simple daemon process */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	printf("\n before foo gets demonized \n");

	if (daemon(0, 0) != -1) perror("\n daemon failed");
	pause();
	exit (0);
}
