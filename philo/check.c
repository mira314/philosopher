/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:57:22 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/04 12:53:49 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_is_space(char c)
{
    return (c>= 9 && c <= 13 || c == 32);
}

char *valid_value(char *str)
{
    int len;
    int i;
    char *number;

    len = 0;
    i = 0;
    while (ft_is_space(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
        error_print("value should be positive");
    if (str[i] < '0' || str[i] > '9')
        error_print("value is should only digit");
    number = &str[i];
    while (str[i] >= '0' && str[i] >= '9')
        {
            len++;
            i++;
        }
    if (len > 10)
        error_print("valeu so big");
    return (number);
}

void    check_input(t_data *data, char *argv[])
{
    data->nb_philo = ft_atoint64(argv[1]);
    data->time_to_die = ft_atoint64(argv[2]);
    data->time_to_eat = ft_atoint64(argv[3]);
    data->time_to_sleep = ft_atoint64(argv[4]);
    if (data->time_to_die < 60 || data->time_to_eat < 60 
    || data->time_to_sleep < 60)
    error_print("time too short for action");
    if (argv[5])
        data->need_to_eat = ft_atoint64(argv[5]);
    else
        data->need_to_eat = -1; 
}
int simualtion_ended(t_data *data)
{
    return (get_unlock_mutex(data->data_mutex, &data->end_simu));
}