/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:32:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/08 20:11:45 by eassouli         ###   ########.fr       */
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

	pthread_mutex_lock(&philo->mutex); // unlock all mutex at the end if die to unlock loop
	time = get_time() - philo->share->start_time;
	if (action == DIE)
		philo->share->die_time = 0;
	if (philo->share->die_time == 0 && action != DIE)
		exit (0);
	printf("%lld %d %s\n", time, philo->id, state[action]);
	pthread_mutex_unlock(&philo->mutex);
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	while (philo->fork_used == 1)
	{
		// printf("passage %d\n", philo->share->die_time);
		if (philo->share->die_time == 0)
		{
			pthread_mutex_unlock(&philo->mutex);
			exit (0);
		}
	}
	philo->fork_used = 1;
	pthread_mutex_unlock(&philo->mutex);
}

void	return_fork(t_philo *philo_one, t_philo *philo_two)
{
	philo_two->fork_used = 0;
	pthread_mutex_lock(&philo_one->mutex);
	philo_one->fork_used = 0;
	pthread_mutex_unlock(&philo_one->mutex);
}

t_philo	*second_fork(t_philo *philo)
{
	if (philo->next)
		return (philo->next);
	else
		return (philo->first);
}

void	philo_eats(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pick_fork(second_fork(philo));
		pick_fork(philo);
		print_state(EAT, philo);
		philo->last_feast = get_time(); // set avant ou apres affichage ?
		yousleep(philo->share->eat_time, philo);
		return_fork(second_fork(philo), philo);
	}
	else
	{
		pick_fork(philo);
		pick_fork(second_fork(philo));
		print_state(EAT, philo);
		philo->last_feast = get_time(); // set avant ou apres affichage ?
		yousleep(philo->share->eat_time, philo);
		return_fork(philo, second_fork(philo));
	}
}

void	philo_sleeps(t_philo *philo)
{
	print_state(SLEEP, philo);
	yousleep(philo->share->sleep_time, philo);
}

void	*routine(void *list) //if odd right else even left
{
	while (((t_philo *)list)->feast != 0)
	{
		philo_eats((t_philo *)list);
		philo_sleeps(((t_philo *)list));
		print_state(THINK, (t_philo *)list);
		if (((t_philo *)list)->feast > 0)
			((t_philo *)list)->feast--;
	}
	// printf("passage id : %d\n", ((t_philo *)list)->id);
	return (NULL); //
}
