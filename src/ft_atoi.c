/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:12:10 by theog             #+#    #+#             */
/*   Updated: 2024/12/05 02:58:52 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_isnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+') && ft_isdigit(str[i + 1]) == 0)
			return (0);
		if (i == 0 && (str[i] == '+') && ft_isdigit(str[i + 1]) == 1)
			i++;
		else if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	long	i;

	i = 0;
	sign = 1;
	result = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign > __INT_MAX__)
		return (-1);
	if (result * sign < -2147483648)
		return (-1);
	return (result * sign);
}