/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:12:23 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 03:00:07 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define NB_MAX_PHILO 200
# define RUN 0
# define STOP 1

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long int		*start_time;
	pthread_mutex_t	lastmeal_time_m;
	long int		lastmeal_time;
	pthread_mutex_t	nb_meals_m;
	int				nb_meals;
	pthread_mutex_t	is_not_eating_mutex;
	bool			is_not_eating;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*speaker;
	pthread_mutex_t	*status_m;
	bool			*status;
	int				time2eat;
	int				time2sleep;
}					t_philo;

typedef struct s_table
{
	int				number_of_philo;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				nb_meals_wanted;
	long int		start_time;
	t_philo     	philo[NB_MAX_PHILO];
	pthread_mutex_t	forks[NB_MAX_PHILO];
	pthread_mutex_t	speaker;
	pthread_mutex_t	status_m;
	bool			status;
}					t_table;

long int	get_time(void);

#endif
