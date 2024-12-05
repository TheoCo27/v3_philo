/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:11:39 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 18:44:41 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philo[i].lastmeal_time_m);
		pthread_mutex_destroy(&table->philo[i].nb_meals_m);
		pthread_mutex_destroy(&table->philo[i].is_not_eating_m);
		i++;
	}
	pthread_mutex_destroy(&table->speaker);
	pthread_mutex_destroy(&table->status_m);
	return (EXIT_SUCCESS);
}
