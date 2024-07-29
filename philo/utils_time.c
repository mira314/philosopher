/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:44:41 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 13:56:43 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t get_time(void)
{
    struct timeval tv;
    uint64_t seconde;
    uint64_t microseconde;
    uint64_t milliseconds;

    gettimeofday(&tv, NULL);
    seconde = tv.tv_sec * 1000;
    microseconde = tv.tv_usec / 1000;
    milliseconds = seconde + microseconde;
    return (milliseconds);
}

int    ft_do_usleep(uint64_t time)
{
    uint64_t start_time;
    uint64_t temp;

    start_time = get_time();
    while (1)
    {
        temp = get_time();
        temp = temp - start_time;
        if (temp >= time)
            break ;
        usleep(100);
    }
    return (0);
}

void time_update(t_data *data)
{
    data->time_stamp = (get_time() - data->time_start);
}