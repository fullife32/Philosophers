/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:03 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/02 18:00:50 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** - Arguments -
** number_of_philosophers time_to_die time_to_eat time_to_sleep
** [number_of_times_each_philosopher_must_eat]
*/

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		status;

	if (ac < 5 || ac > 6 || av_is_onlynum(ac, av) == 0)
		return (print_error());
	if (ft_atol(av[1]) == 0)
		return (print_error());
	philo = malloc_list(av);
	status = start_threads(philo);
	if (status == EXIT_FAILURE)
	{
		perror("start_threads");
		free_philo(&philo);
		return (EXIT_FAILURE);
	}
	printf("tout est bon\n"); //
	free_philo(&philo);
	return (EXIT_SUCCESS);
}
