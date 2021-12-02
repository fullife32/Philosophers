#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	//usleep(1000000);
	while (end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec) < 1) {
		gettimeofday(&end, NULL);
	}
	printf("%0.8f\n", end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec));

	return (0);
}
