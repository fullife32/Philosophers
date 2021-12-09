/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:56:11 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 18:56:32 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **first, t_share *share)
{
	t_philo	*philo;
	t_philo	*save_next;

	philo = *first;
	while (philo)
	{
		save_next = philo->next;
		pthread_mutex_destroy(&philo->mutex);
		free(philo);
		philo = save_next;
	}
	pthread_mutex_destroy(&share->mutex);
}
