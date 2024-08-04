/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:18:52 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/04 13:36:44 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_till_theads_is_ready(philo->data);
    return (NULL);
}
void    simulation_start(t_data *data)
{
    int i

    i = 0;
    if (data->need_to_eat == 0)
        return ;
    else if (data->nb_philo == 1)
        ;/// a faire
    else
    {
        while(data->nb_philo > i)
        {
            alloc_pthread(&data->philo[i].thread_id, simulation,
            data->philo[i], 7);
        }
    }
    data->time_start = 
    set_unlock_mutex(&data->data_mutex, data->theards_is_ready, 1)
}