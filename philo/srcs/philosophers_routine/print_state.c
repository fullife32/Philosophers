/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:46:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 20:57:06 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int action, t_philo *philo)
{
	static char	*state[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died"};
	long long	time;

	pthread_mutex_lock(&philo->share->dead_mutex);
	time = get_time() - philo->share->start_time;
	if (action == DIE)
		philo->share->die_time = 0;
	else if (philo->share->die_time == 0)
	{
		pthread_mutex_unlock(&philo->share->dead_mutex);
		return ;
	}
	printf("%lld %d %s\n", time, philo->id, state[action]);
	pthread_mutex_unlock(&philo->share->dead_mutex);
}
