/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:19:05 by eassouli          #+#    #+#             */
/*   Updated: 2021/12/03 17:34:45 by eassouli         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				die_time;
	int				eat_time;
	float			last_feast;
	int				sleep_time;
	// int				think_time;
	int				feast;
	int				fork_used;
	float			start_time;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_philo	*first;
}				t_philo;

/*
** Prototypes
*/

int			av_is_onlynum(int ac, char **av);

long		ft_atol(const char *str);

t_philo		*malloc_list(char **av);
t_philo		*malloc_philo(char **av);
void		free_philo(t_philo **first);

int			start_threads(t_philo *first);

void		*routine(void *list);

void		print_state(int action, t_philo *philo);

float		get_time(void);
float		time_in_sec(struct timeval time);
void		yousleep(int time_to_sleep, t_philo *philo);
void		is_dead(t_philo *philo);

int			print_error(void);

#endif