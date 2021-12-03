/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:58 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/03 17:45:30 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	time_in_sec(struct timeval time)
{
	float	time_sec;

	time_sec = (float)time.tv_sec + 1e-6 * (float)time.tv_usec;
	return (time_sec);
}

float	get_time(void)
{
	struct timeval	time;

	time.tv_sec = 0;
	time.tv_usec = 0;
	gettimeofday(&time, NULL); //secure ?
	return (time_in_sec(time));
}

void	yousleep(int time_to_sleep, t_philo *philo)
{
	float	end_time;

	end_time = get_time();
	end_time += (float)time_to_sleep;
	while (end_time < get_time()) // <= ?
		is_dead(philo);
	// usleep leger pour alleger le proco d'apres lylian
}

void	is_dead(t_philo *philo)
{
	float	time;
	float	die_time_sec;

	time = get_time();
	die_time_sec = (float)philo->die_time / 1000;
	if (philo->last_feast + die_time_sec > time
		&& philo->start_time + die_time_sec > time)
	{
		print_state(DIE, philo);
		exit (1);
	}
}

// int get_time()
// {
// 	// struct timeval new_time;
// 	(void)start;
// 	(void)ms;

// 	gettimeofday(&new_time, NULL);
// 	usleep(ms);
// 	while (end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec) <) {
// 		gettimeofday(&end, NULL); // microsleep pour liberer un peu le proco
// 	}
// 	printf("%0.8f\n", end.tv_sec - start.tv_sec + 1e-6*(end.tv_usec - start.tv_usec));

// 	return (0);
// }
