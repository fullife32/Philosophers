/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_time_to_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:53 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/13 18:25:34 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_die(int time, int dead_time, int feast, t_philo *philo)
{
	if (time > dead_time && feast != 0)
	{
		print_state(DIE, philo);
		return (1);
	}
	return (0);
}

void	is_dead(t_philo *first, t_share *share)
{
	t_philo		*philo;
	long long	time;
	long long	dead_time;
	int			feast;

	feast = -1;
	while (feast != 0)
	{
		feast = 0;
		philo = first;
		while (philo)
		{
			time = get_time();
			pthread_mutex_lock(&share->eat_mutex);
			dead_time = philo->last_feast + share->die_time;
			feast = philo->feast;
			pthread_mutex_unlock(&share->eat_mutex);
			if (print_die(time, dead_time, feast, philo) == 1)
				return ;
			philo = philo->next;
		}
		usleep(100);
	}
}
