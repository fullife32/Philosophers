/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:06:55 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/08 19:33:08 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_share	get_shared_values(char **av)
{
	t_share	share;

	share.die_time = ft_atol(av[2]);
	share.eat_time = ft_atol(av[3]);
	share.sleep_time = ft_atol(av[4]);
	if (av[5])
	{
		if (ft_atol(av[5]) == 0) // trouver une autre solution
			exit (0);
	}
	return (share);
}

void	free_philo(t_philo **first)
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
}

t_philo	*malloc_philo(char **av)
{
	static int	id = 1;
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = id++;
	philo->feast = -1;
	if (av[5])
		philo->feast = ft_atol(av[5]);
	philo->fork_used = 0;
	pthread_mutex_init(&philo->mutex, NULL); // secure
	philo->next = NULL;
	philo->first = NULL;
	return (philo);
}

t_philo	*malloc_list(char **av)
{
	int		id;
	int		nb_of_philo;
	t_philo	*first;
	t_philo	*philo;

	id = 1;
	nb_of_philo = ft_atol(av[1]);
	philo = malloc_philo(av);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	first = philo;
	while (id++ < nb_of_philo)
	{
		philo->next = malloc_philo(av);
		if (philo == NULL)
		{
			free_philo(&first);
			exit(EXIT_FAILURE);
		}
		philo = philo->next;
	}
	philo->first = first;
	return (first);
}
