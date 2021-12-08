/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:58 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/08 19:48:40 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL); //secure ?
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	yousleep(int time_to_sleep, t_philo *philo)
{
	long long	actual;
	long long	end;

	actual = get_time();
	end = get_time() + time_to_sleep;
	while (actual < end)
	{
		if (philo->share->die_time == 0)
			exit (0);
		usleep(time_to_sleep); // check si mort exit
		actual = get_time();
	}
}

void	is_dead(t_philo *first) // appel dans le parent
{
	t_philo		*philo;
	t_share		*share;
	long long	time;
	int			feast;

	share = first->share;
	feast = -1;
	while (feast != 0)
	{
		feast = 0;
		philo = first;
		while (philo)
		{
			time = get_time();
			if (time > philo->last_feast + share->die_time)
			{
				print_state(DIE, philo);
				return ;
			}
			feast = philo->feast;
			philo = philo->next;
		}
	}
}
