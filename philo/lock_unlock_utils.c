/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:05:53 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/06 14:50:47 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_unlock_mutex(pthread_mutex_t *mutex,int *dest, int code)
{
    alloc_mutex(mutex, 1);
    *dest = value;
    alloc_mutex(mutex, 2);
}

int get_unlock_mutex(pthread_mutex_t *mutex, int *value)
{
    int result;
    alloc_mutex(mutex, 1);
    result = *value;
    alloc_mutex(mutex, 2);
    return (result);
}

void    set_unlock_mutex_uint64(pthread_mutex_t *mutex,uint64_t *dest, int code)
{
    alloc_mutex(mutex, 1);
    *dest = value;
    alloc_mutex(mutex, 2);
}

uint64_t get_unlock_mutex_uint64(pthread_mutex_t *mutex, uint64_t *value)
{
    uint64_t result;
    alloc_mutex(mutex, 1);
    result = *value;
    alloc_mutex(mutex, 2);
    return (result);
}
