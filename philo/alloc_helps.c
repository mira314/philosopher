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
the variable code is value defin in the header
code == 1 is for pthread_mutex_lock
code == 2 is for pthread_mutex_unlock
code == 3 is for pthread_mutex_init
code == 4 is for pthread_mutex_destroy
code == 5 is for join
code == 6 is for detach
code == 7 for create
*/
static void error_check_pthread(int status, int code)
{
    if (status == 0)
        ;
    if (EAGAIN == status)
        error_print("no resouces to create");
    else if (EPERM == status)
        error_print("permission error")
    else if (EINVAL == status && code == 7)
        error_print("attribute invalide");
    else if (EINVAL == status && (code == 5 || code == 6))
        error_print("not joinable");
    else if (ESRCH == status)
        error_print("not found");
    else if (EDEADLK == status)
        error_print("deadlock detect");
}
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

void    alloc_pthread(pthread_t *thread, void *(*f)(void *), 
    void *data, int code)
{
    if (code == 7)
        error_check_pthread(pthread_create(thread, NULL, f, data), code);
    else if (code == 5)
        error_check_pthread(pthread_join(*thread,, NULL), code);
    else if (code == 6)
        error_check_pthread(pthread_detach(*thread), code);
    else
        error_print("code error");
 }


