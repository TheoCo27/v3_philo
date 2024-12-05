/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:12:40 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 18:22:40 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int	check_arg(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > NB_MAX_PHILO)
	{
		printf("Bad NB of PHILO\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("time below 60ms\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 0)
	{
		printf("Bad number of meals\n");
		return (1);
	}
	return (0);
}