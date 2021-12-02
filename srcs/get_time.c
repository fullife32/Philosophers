/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:58 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/02 15:23:21 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Arguments -
** number_of_philosophers time_to_die time_to_eat time_to_sleep
** [number_of_times_each_philosopher_must_eat]
*/

#include "philo.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	//usleep(1000000);
	while (end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec) < 1) {
		gettimeofday(&end, NULL); // microsleep pour liberer un peu le proco
	}
	printf("%0.8f\n", end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec));

	return (0);
}
