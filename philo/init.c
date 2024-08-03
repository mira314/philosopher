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
    data->philo = do_malloc(sizeof(t_philo) * data->nb_philo);
    data->fork = do_malloc(sizeof(t_philo) * data->nb_philo);
    while (i < data->nb_philo)\
    {
        alloc_mutex(data->fork[i].fork, 3);
        table->fork[i].fork_id = i;
        i++;
    }
    philo_init(data);
}

void    philo_init(t_data *data)
{
    int i;
    t_philo *philo;

    i = 0;
    while (data->nb_philo > i)
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
     

}