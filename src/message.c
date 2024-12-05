/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:13:01 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 02:57:23 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_strncmp(char *msg, char *cmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (msg[i] != cmp[i])
			return (false);
		i++;
	}
	return (true);
}

int	message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->speaker);
	pthread_mutex_lock(philo->status_m);
	if (*philo->status == RUN && ft_strncmp(msg, "died", 4) == false)
	{
		pthread_mutex_unlock(philo->speaker);
		pthread_mutex_unlock(philo->status_m);
		return (EXIT_FAILURE);
	}
	printf("%ld %d %s\n", (get_time() - *philo->start_time),
		philo->id, msg);
	pthread_mutex_unlock(philo->speaker);
	pthread_mutex_unlock(philo->status_m);
	return (EXIT_SUCCESS);
}
