/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:32:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/03 17:44:06 by eassouli         ###   ########.fr       */
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
	int			time_ms;

	// pthread_mutex_lock() // lock mutex pour pas ecrire par dessus
	time_ms = (get_time() - philo->start_time); // check calcul
	// printf("%f %f\n", get_time(), philo->start_time);
	printf("%d %d %s\n", time_ms, philo->id, state[action]);
}

// int	philo_eats(t_philo *philo)
// {
// 	if (philo->next)
// 	{
// 		while (philo->fork_used == 1 && philo->next->fork_used == 1)
// 		{
// 			//check dead
// 		}
		
// 	}
// }

void	*routine(void *list)
{
	while (((t_philo *)list)->feast != 0)
	{
		// philo_eats(((t_philo *)list));
		print_state(FORK, (t_philo *)list);
		if (((t_philo *)list)->feast > 0)
			((t_philo *)list)->feast--;
		// philo_sleeps(((t_philo *)list));
		// philo_thinks(((t_philo *)list));
	}
	// printf("passage id : %d\n", ((t_philo *)list)->id);
	return (NULL); //
}
