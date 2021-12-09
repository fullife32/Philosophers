/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_time_to_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:53 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 18:52:58 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dead(t_philo *first, t_share *share) // appel dans le parent
{
	t_philo		*philo;
	long long	time;
	int			feast;

	feast = -1;
	while (feast != 0)
	{
		feast = 0;
		philo = first;
		while (philo)
		{
			time = get_time();
			if (time > philo->last_feast + share->die_time)
			{
				print_state(DIE, philo);
				return ;
			}
			feast = philo->feast;
			philo = philo->next;
		}
	}
}
