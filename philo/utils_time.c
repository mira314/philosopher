/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:44:41 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 11:17:22 by vrandria         ###   ########.fr       */
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
    seconde = tv.tv_sec * 100;
    microseconde = tv.tv_usec / 1000;
    milliseconds = seconde + microseconde;
    return (milliseconds);
}

void    ft_do_usleep(uint64_t time)
{
    uint64_t start_time;

    start_time = get_time();
    while ((get_time() - start_time) < time)
    {
        usleep(100);
    }
}