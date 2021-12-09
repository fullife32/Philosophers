/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:32:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 18:49:43 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleeps(t_philo *philo)
{
	print_state(SLEEP, philo);
	yousleep(philo->share->sleep_time, philo);
}

void	*routine(void *list)
{
	while (((t_philo *)list)->feast != 0)
	{
		philo_eats((t_philo *)list);
		philo_sleeps(((t_philo *)list));
		print_state(THINK, (t_philo *)list);
		if (((t_philo *)list)->feast > 0)
			((t_philo *)list)->feast--;
	}
	return (NULL);
}
