/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:48:35 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 20:54:53 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*second_fork(t_philo *philo)
{
	if (philo->next)
		return (philo->next);
	else
		return (philo->first);
}

void	eat_with_two_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->share->eat_mutex);
	philo->last_feast = get_time();
	pthread_mutex_unlock(&philo->share->eat_mutex);
	print_state(EAT, philo);
	yousleep(philo->share->eat_time, philo);
}

int	philo_alone(t_philo *philo)
{
	if (philo->next == NULL && philo->first == philo)
	{
		yousleep(philo->share->die_time + 60, philo);
		return (1);
	}
	return (0);
}

void	philo_eats(t_philo *philo)
{
	t_philo	*philo_two;

	philo_two = second_fork(philo);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->mutex);
		print_state(FORK, philo);
		if (philo_alone(philo) == 1)
			exit(0);
		pthread_mutex_lock(&philo_two->mutex);
		print_state(FORK, philo);
		eat_with_two_forks(philo);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo_two->mutex);
		print_state(FORK, philo);
		pthread_mutex_lock(&philo->mutex);
		print_state(FORK, philo);
		eat_with_two_forks(philo);
	}
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo_two->mutex);
}
