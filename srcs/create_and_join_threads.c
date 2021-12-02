/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/02 18:10:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *list)
{
	t_philo	*philo;

	philo = (t_philo *)list;
	printf("passage id : %d\n", philo->id);
	return (NULL);
}

int	start_threads(t_philo *first) //secure
{
	t_philo	*philo;
	int		status;

	philo = first;
	while (philo)
	{
		status = pthread_create(&philo->thread, NULL, &routine, philo);
		if (status != 0)
			return (EXIT_FAILURE);
		philo = philo->next;
	}
	philo = first;
	while (philo)
	{
		status = pthread_join(philo->thread, NULL);
		if (status != 0)
			return (EXIT_FAILURE);
		philo = philo->next;
	}
	return (EXIT_SUCCESS);
}
