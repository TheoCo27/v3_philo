/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:12:48 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 18:55:19 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (init_all(&table, argc, argv) == 1)
		return (1);
	if (table.nb_philo == 1)
		lonely_philo(&table);
	ft_clean(&table);
	return (0);
}