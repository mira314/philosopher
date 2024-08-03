/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:21:57 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/03 17:57:42 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	error_print(char *error)
{
	printf("%s\n",error);
	exit(EXIT_FAILURE);
}
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

uint64_t	ft_atoint64(const char *str)
{
	uint64_t	result;
	int		i;

	i = 0;
	result = 0;
	str = valid_value(str);

	while (str[i]>= '0' && str[i]<= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result);
}
