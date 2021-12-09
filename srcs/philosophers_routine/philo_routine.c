/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:32:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 20:32:23 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleeps(t_philo *philo)
{
	print_state(SLEEP, philo);
	yousleep(philo->share->sleep_time, philo);
}

int		dead_philo(t_share *share)
{
	int	dead;

	pthread_mutex_lock(&share->dead_mutex);
	dead = share->die_time;
	pthread_mutex_unlock(&share->dead_mutex);
	if (dead == 0)
		return (1);
	return (0);
}

void	*routine(void *list)
{
	t_philo	*philo;

	philo = (t_philo *)list;
	while (philo->feast != 0 && dead_philo(philo->share) == 0)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		print_state(THINK, philo);
		if (philo->feast > 0)
			philo->feast--;
	}
	return (NULL);
}
