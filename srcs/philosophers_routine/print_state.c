/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:46:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 18:47:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_all(t_philo *first)
{
	while (first)
	{
		pthread_mutex_unlock(&first->mutex);
		first = first->next;
	}
}

void	print_state(int action, t_philo *philo)
{
	static char	*state[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died"};
	long long	time;

	pthread_mutex_lock(&philo->share->mutex); // unlock all mutex at the end if die to unlock loop
	time = get_time() - philo->share->start_time;
	if (action == DIE)
	{
		philo->share->die_time = 0;
		unlock_all(philo->first);
	}
	else if (philo->share->die_time == 0)
	{
		unlock_all(philo->first);
		exit (0);
	}
	printf("%lld %d %s\n", time, philo->id, state[action]);
	pthread_mutex_unlock(&philo->share->mutex);
}
