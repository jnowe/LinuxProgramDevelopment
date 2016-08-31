/* sense when the content of a file is modified */
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>


int main(int argc, char *argv[])
{
	int fd, nb, bufsize;
	char *buf;
	struct inotify_event *ev;
	unsigned long le_cookie;

	if (argc < 2) {perror("\n arguments"); return -1;}

    	bufsize = getpagesize ();
    	buf = malloc (bufsize);
	fd = inotify_init();
	printf("inotify_add_watch = %d \n",inotify_add_watch(fd, argv[1], IN_ALL_EVENTS));

	
	for(;;)
	{
		//memset (buf, 0, bufsize);
		sleep(1);
		printf ("\nnb from read=%d\n\n", nb);
		nb = read (fd, buf, bufsize);
                
		ev = (struct inotify_event *)(buf);
		
		if (le_cookie != ev->cookie )
		{
			printf(" \n A change just took place in %s ", argv[1]);
			le_cookie = ev->cookie;
		}
		
	}
	return 0;
}

