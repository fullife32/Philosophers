/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:58 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/07 14:51:11 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// long long	time_in_sec(struct timeval time)
// {
// 	long long	time_sec;

// 	time_sec = (float)time.tv_sec + (float)time.tv_usec * 1000 * 1000;
// 	return (time_sec);
// }

long long	get_time(void)
{
	struct timeval	time;
	long long	time_sec;

	time.tv_sec = 0;
	time.tv_usec = 0;
	gettimeofday(&time, NULL); //secure ?
	time_sec = time.tv_sec / 1000 + time.tv_usec * 1000;
	return (time_sec);
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
