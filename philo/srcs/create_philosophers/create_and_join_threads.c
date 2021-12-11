/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/11 15:21:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_even(t_philo *philo, t_share *share)
{
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

int	create_odd(t_philo *philo, t_share *share)
{
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
	return (EXIT_SUCCESS);
}

int	create_threads(t_philo *first, t_share *share)
{
	share->start_time = get_time();
	if (create_odd(first, share) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	usleep(100);
	if (create_even(first, share) == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
