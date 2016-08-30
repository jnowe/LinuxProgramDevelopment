/* use gdb to check values */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>

void doit (unsigned long chunk_size)
{
	char *buf;
	buf = malloc (chunk_size);
}

int main (int argc, char *argv[])
{
	/* for fun: limit stack size to 1M */
	/* struct rlimit r1 = {1024, 1024}; */
	/* setrlimit (RLIMIT_STACK, &r1); */

	struct mallinfo mymallinfo;
	mymallinfo = mallinfo();

	doit(100);
	mymallinfo = mallinfo();

	doit(1000);
	mymallinfo = mallinfo();

	doit(10000);
	mymallinfo = mallinfo();

        doit(100000);
	mymallinfo = mallinfo();
	malloc_stats();

        doit(1000000);
	mymallinfo = mallinfo();
	malloc_stats();

exit(0);
}
