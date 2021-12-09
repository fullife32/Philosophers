/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yousleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:16:50 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 19:24:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	yousleep(int time_to_sleep, t_philo *philo)
{
	long long	actual;
	long long	end;
	int			die_time;

	actual = get_time();
	end = get_time() + time_to_sleep;
	while (actual < end)
	{
		pthread_mutex_lock(&philo->share->mutex);
		die_time = philo->share->die_time;
		pthread_mutex_unlock(&philo->share->mutex);
		if (die_time == 0)
			exit (0);
		usleep(time_to_sleep); // check si mort exit
		actual = get_time();
	}
}
