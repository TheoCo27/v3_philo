/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:13:36 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 18:57:10 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lonely_philo(t_table *table)
{
	message(&table->philo[0], "is thinking");
	message(&table->philo[0], "has taken a fork");
	usleep(table->time2die * 1000);
	message(&table->philo[0], "died");
}
