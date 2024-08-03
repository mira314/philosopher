/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:51:58 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/03 17:57:40 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_malloc(size_t bytes)
{
	void	*result;
	result = malloc(bytes);
	if (!result)
		error_print("Error with malloc");
	return (result);
}

/* 
the variable code is valeu of type enum
code == 1 is for pthread_mutex_lock
code == 2 is for pthread_mutex_unlock
code == 3 is for pthread_mutex_init
code == 4 is for pthread_mutex_destroy
*/

static void error_check_mutex(int status, int code)
{
    if (status == 0)
        return ;
    if (EINVAL == status && (code == 1 || code == 2))
        error_print("mutex_error");
    else if (EINVAL == status && code == 3)
        error_print("atribut error for mutex");
    else if (EDEADLK == status)
        error_print("error deadlock waiting for mutex");
    else if (EPERM ==  status)
        error_print("thread does not lock on mutex");
    else if (ENOMEN ==  status)
        error_print("not enough memory");
    else if (EBUSY ==  status)
        error_print("mutex locked");
}

void    alloc_mutex(pthread_mutex_t *mutex, int code)
{
    if (code == 1)
        error_check_mutex(pthread_mutex_lock(mutex), code);
    else if (code == 2)
        error_check_mutex(pthread_mutex_unlock(mutex), code);
    else if (code == 3)
        error_check_mutex(pthread_mutex_init(mutex, NULL), code);
    else if (code == 4)
        error_check_mutex(pthread_mutex_destroy(mutex), code);
    else
        error_print("code no handel");
}

