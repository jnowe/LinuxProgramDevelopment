/* program that will display its pid, ppid and pgid, CPU time limits the modify it's current CPU limit and exceed it causing it to be killed */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	pid_t mypid;
	pid_t myppid;
	pid_t mypgid;
	struct rlimit myrlim[RLIM_NLIMITS];
	struct rusage myrusage;
	unsigned long i = 1;

	mypid = getpid();
	myppid = getppid();
	mypgid = getpgid(mypid);
	myrlim[RLIMIT_CPU];
	if ((getrlimit(RLIMIT_CPU, &myrlim[RLIMIT_CPU])) == -1) perror("\n getrlimit[RLIMIT_CPU] failed:");
	if (getrusage(RUSAGE_SELF, &myrusage) == -1) perror("\n getrusage failed:");
	

	printf("\n PID      = %d \n Parent PID = %d \n Group PID = %d \n", mypid, myppid, mypgid);
	printf("\n Init Current CPU time limit = %lu \n Init Maximum CPU time limit = %lu \n", myrlim[RLIMIT_CPU].rlim_cur, myrlim[RLIMIT_CPU].rlim_max);

	myrlim[RLIMIT_CPU].rlim_cur = 1;
	if ((setrlimit(RLIMIT_CPU, &myrlim[RLIMIT_CPU])) == -1) perror("\n setrlimit[RLIMIT_CPU] failed:");
	printf("\n NEW Current CPU time limit = %lu \n NEW Maximum CPU time limit = %lu \n", myrlim[RLIMIT_CPU].rlim_cur, myrlim[RLIMIT_CPU].rlim_max);

	printf(" \n System Time used = %ld.%06ld \n", myrusage.ru_stime.tv_sec, myrusage.ru_stime.tv_usec);
	printf(" \n Page faults = %ld \n", myrusage.ru_majflt);
	printf(" \n Involuntary = %lu \n", myrusage.ru_nivcsw);

	for (i = 1; i != 0 ; i++)
	{
		// do nothing
	}
	printf("\n Process will finish nicely.i \n");
	return 0;

}
