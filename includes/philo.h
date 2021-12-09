/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:19:05 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/09 19:27:35 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** - External functions -
** memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create,
** pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy,
** pthread_mutex_lock, pthread_mutex_unlock
*/

/*
** Includes
*/

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <errno.h>

/*
** Defines
*/

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

/*
** Structures
*/

typedef struct	s_share
{
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long long		start_time;
	pthread_mutex_t	mutex;
}				t_share;

typedef struct	s_philo
{
	int				id;
	int				feast;
	long long		last_feast;
	t_share			*share;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_philo	*first;
}				t_philo;

/*
** Prototypes
*/

int			av_is_onlynum(int ac, char **av);

t_share		get_shared_values(char **av);
t_philo		*malloc_list(char **av, t_share *share);

int			create_threads(t_philo *first, t_share *share);
int			join_threads(t_philo *first);

long long	get_time(void);

void		yousleep(int time_to_sleep, t_philo *philo);

void		is_dead(t_philo *first, t_share *share);

void		*routine(void *list);

void		philo_eats(t_philo *philo);

void		print_state(int action, t_philo *philo);

void		free_philo(t_philo **first, t_share *share);

int			print_error(void);

long		ft_atol(const char *str);

#endif