/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:00:39 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 19:21:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(void)
{
	printf("Usage: ./philo number_of_philosophers > 0 time_to_die (ms)");
	printf(" time_to_eat (ms) time_to_sleep (ms)");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}
