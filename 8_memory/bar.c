
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>

void doit_100M (void)
{
	char *buf;
	buf = malloc (100000000);
}

int main (int argc, char *argv[])
{
	int j;
	struct mallinfo mymallinfo;
	mymallinfo = mallinfo();

	for (j = 0; j < 20000; j++)
	{
		doit_100M();
        	printf("I allocated the %3d buffer \n", j);
	        mymallinfo = mallinfo();
	}
exit(0);
}
