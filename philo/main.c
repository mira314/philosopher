/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:17:42 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 13:51:01 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
static check_correct_arg(int argc, char const *argv[])
{
    int i;
    if (argc == 5 || argc == 6)
    {
        i = 1;
        while (argv[i])
        i++;
    }

}
*/
t_philo *ft_setup_philo(t_data *data)
{
    t_philo *philo;
    int i;

    i = 0;
    philo = malloc(sizeof(t_philo) * (data->nb_philo));
    if (!philo)
        return (0);
    while (i < data->nb_philo)
        {
            philo[i].id = i + 1;
            philo[i].nb_eat = 0;
            i++;
        }
    return (philo);
}

void ft_setup(int argc, char *argv[], t_data *data)
{
    data->time_start = get_time();
    data->nb_philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_steep = ft_atoi(argv[4]);
    data->time_stamp = 0;
    if (argc == 6)
        data->nb_need_eat = ft_atoi(argv[5]);
}
void time_update(t_data *data)
{
    data->time_stamp = (get_time() - data->time_start);
}
int main(int argc, char *argv[])
{
    t_data data;
    t_philo *philo;
    ft_setup(argc, argv, &data);
    philo = ft_setup_philo(&data);
    printf("philo %d\n", philo[1].id);
    free(philo);
    return 0;
}
