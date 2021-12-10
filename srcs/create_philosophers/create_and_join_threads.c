/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/10 18:44:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo *first, t_share *share) //secure
{
	t_philo	*philo;

	philo = first;
	share->start_time = get_time();
	while (philo)
	{
		if (philo->id % 2 != 0)
		{
			philo->share = share;
			philo->last_feast = share->start_time;
			if (pthread_create(&philo->thread, NULL, &routine, philo) != 0)
				return (EXIT_FAILURE);
		}
		philo = philo->next;
	}
	philo = first;
	usleep(100); // sleep plus long
	while (philo)
	{
		if (philo->id % 2 == 0)
		{
			philo->share = share;
			philo->last_feast = share->start_time;
			if (pthread_create(&philo->thread, NULL, &routine, philo) != 0)
				return (EXIT_FAILURE);
		}
		philo = philo->next;
	}
	return (EXIT_SUCCESS);
}

int	join_threads(t_philo *first)
{
	t_philo	*philo;

	philo = first;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			return (EXIT_FAILURE);
		philo = philo->next;
	}
	return (EXIT_SUCCESS);
}
