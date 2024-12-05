/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:11:25 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 18:47:23 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	table->start_time = get_time();
	if (check_arg(argc, argv) == 1)
		return (1);
	table->nb_philo = ft_atoi(argv[1]);
	table->time2die = ft_atoi(argv[2]);
	table->time2eat = ft_atoi(argv[3]);
	table->time2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->nb_meals_wanted = ft_atoi(argv[5]);
	else
		table->nb_meals_wanted = -1;
	table->status = RUN;
	return (0);
}

int init_philos(t_table *table)
{
	int i;

	i = 0;
	while(i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].nb_meals = 0;
		table->philo[i].is_not_eating = true;
		table->philo[i].status = &table->status;
		table->philo[i].time2eat = table->time2eat;
		table->philo[i].time2sleep = table->time2sleep;
		table->philo[i].start_time = &table->start_time;
		table->philo[i].lastmeal_time = table->start_time;
		pthread_mutex_init(&table->philo[i].lastmeal_time_m, NULL);
		pthread_mutex_init(&table->philo[i].nb_meals_m, NULL);
		pthread_mutex_init(&table->philo[i].is_not_eating_m, NULL);
		i++;
	}
	return (0);
}

int init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		if (i != 0)
			table->philo[i].left_fork = &table->forks[i - 1];
		table->philo[i].right_fork = &table->forks[i];
		i++;
	}
	table->philo[0].left_fork = &table->forks[table->nb_philo - 1];
	return (EXIT_SUCCESS);
	return (0);
}

int init_mutex(t_table *table)
{
		int	i;

	i = 0;
	pthread_mutex_init(&table->status_m, NULL);
	while (i < table->nb_philo)
	{
		table->philo[i].status_m = &table->status_m;
		i++;
	}
	i = 0;
	pthread_mutex_init(&table->speaker, NULL);
	while (i < table->nb_philo)
	{
		table->philo[i].speaker = &table->speaker;
		i++;
	}
	return (0);
}

int init_all(t_table *table, int argc, char **argv)
{
	if (init_table(table, argc, argv))
	{
		printf("Error: init_table failed\n");
		return (1);
	}
	if (init_philos(table))
	{
		printf("Error: init_philosophers failed\n");
		return (1);
	}
	if (init_forks(table))
	{
		printf("Error: fork failed\n");
		return (1);
	}
	if (init_mutex(table))
	{
		printf("Error: mutex failed\n");
		return (1);
	}
	return (0);
}
