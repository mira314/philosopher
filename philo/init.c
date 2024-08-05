 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:40:39 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/03 17:57:43 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void    data_init(t_data *data)
{
    int i;

    i = 0;
    data->end_simu = 0;
    data->theards_is_ready = 0;
    data->philo = do_malloc(sizeof(t_philo) * data->nb_philo);
    alloc_mutex(&data->data_mutex, 3);
    data->fork = do_malloc(sizeof(t_philo) * data->nb_philo);
    while (i < (int)data->nb_philo) 
    {
        alloc_mutex(&data->fork[i].fork, 3);
        data->fork[i].fork_id = i;
        i++;
    }
    philo_init(data);
}

void    philo_init(t_data *data)
{
    int i;
    t_philo *philo;

    i = 0;
    alloc_mutex(&data->data_mutex, 3);
    while ((int)data->nb_philo > i)
    {
        philo = data->philo + 1;
        philo->id = i + 1;
        philo->is_eat_max = 0;
        philo->eat_count = 0;
        philo->data = data;
        use_this_forks(philo, data->fork, i);
        i++;
    }
}

void use_this_forks(t_philo *philo, t_forks *forks,int id)
{
    int number_philo;
 
    number_philo = philo->data->nb_philo;
    philo->right_fork = &forks[id];
    philo->left_fork = &forks[(id + 1) % number_philo];
    if (philo->id % 2)
    {
        philo->right_fork = &forks[id];
        philo->left_fork = &forks[(id + 1) % number_philo];
    }
}