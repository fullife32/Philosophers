/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:48:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/03 16:55:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_philo *first) //secure
{
	float			start_time;
	t_philo			*philo;

	philo = first;
	start_time = get_time();
	while (philo)
	{
		philo->start_time = start_time;
		if (pthread_create(&philo->thread, NULL, &routine, philo))
			return (EXIT_FAILURE);
		philo = philo->next;
	}
	philo = first;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL)) // ajouter valeur de retour la structure
			return (EXIT_FAILURE);
		philo = philo->next;
	}
	return (EXIT_SUCCESS);
}
