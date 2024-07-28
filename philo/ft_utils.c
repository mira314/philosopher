/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:21:57 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 10:54:52 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i]>= '0' && str[i]<= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return ((int)result * sign);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

uint64_t	ft_atol64(const char *str)
{
	uint64_t	result;
	int		i;

	i = 0;
	result = 0;
	while (str[i]>= '0' && str[i]<= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return ((uint64_t)result);
}