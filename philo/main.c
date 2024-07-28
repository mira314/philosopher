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
int ft_setup_philo(t_data *data)
{
    t_philo *philo;
    
    philo = malloc(sizeof(data)->nb_philo);
    if (!philo)
        return (1);
    return (0);
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
    int i = 50;
    ft_setup(argc, argv, &data);
    while(i--) 
    {
        printf("%d\n", data.time_stamp);
        ft_do_usleep(100);
        time_update(&data);
    }
    return 0;
}
