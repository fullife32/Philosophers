/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:03 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/08 19:45:24 by eassouli         ###   ########.fr       */
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
	t_share	share;
	t_philo	*philo;
	int		status;

	if (ac < 5 || ac > 6 || av_is_onlynum(ac, av) == 0)
		return (print_error());
	if (ft_atol(av[1]) == 0)
		return (print_error());
	share = get_shared_values(av);
	philo = malloc_list(av);
	// printf("passage main\n");
	status = start_threads(philo, &share);
	if (status == EXIT_FAILURE)
	{
		perror("start_threads");
		free_philo(&philo);
		return (EXIT_FAILURE);
	}
	is_dead(philo); // check si philo est mort et mettre value a 1 pour faire exit les autres et qu'ils ne puissent plus ecrire
	join_threads(philo);
	free_philo(&philo);
	return (EXIT_SUCCESS);
}
