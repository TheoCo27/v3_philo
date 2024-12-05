/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:16:01 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 03:01:11 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_time()
{
    
}

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	usleep_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lastmeal_time_m);
	while ((get_time() - philo->lastmeal_time) < philo->time2eat)
	{
		usleep(10);
	}
	pthread_mutex_unlock(&philo->lastmeal_time_m);
}

void	custom_sleep_sleeping(t_philo *philo, long int time)
{
	while (get_time() - time < philo->time2sleep)
	{
		usleep(10);
	}
}