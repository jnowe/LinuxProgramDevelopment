/* open a file and display hex content using UNIX API */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	char buf;
	char pathname[9] = "test.txt";
	int fd = 0, read_ret;

	if ((fd = open(pathname, O_RDONLY, 00777)) == -1)
	{
		printf("\n something went bad. \n");
	        perror("premature fin. ");
		return -1;
	}
	        perror("check .");
		if (argc < 2)
		{
			printf ("\n no argument. \n");
			return -1;
		}		

		if(lseek(fd, atoi(argv[1]), SEEK_SET) == -1) perror("meh ... ");
	do
	{
		read_ret = read(fd, &buf, 1);
		printf("%x ", buf);
	} while ((buf != EOF) && (read_ret > 0));
	perror("fin. ");

	printf("\n");
	return 0;
}



