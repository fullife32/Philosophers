#include "philo.h"

void	*routine(void *truc)
{
	struct timeval	start;
	struct timeval	end;
	int truc_i = (int)truc;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	// usleep(ms);
	while (end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec) <= 0.001)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		// truc_i++;
	}
		gettimeofday(&end, NULL); // microsleep pour liberer un peu le proco
	// }
	printf("%0.4f\n", end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec));
	return (NULL);
}

int main()
{
	// struct timeval new_time;
	
	pthread_t	thread[200];
	int			truc[200];

	for (int i = 0; i < 200; i++)
	{
		truc[i] = 0;
		if (pthread_create(&thread[i], NULL, &routine, (void*)truc[i]))
			return (EXIT_FAILURE);
	}
	for (int i = 0; i < 100; i++)
	{
		if (pthread_join(thread[i], NULL)) // ajouter valeur de retour la structure
			return (EXIT_FAILURE);
	}
	return (0);
}
