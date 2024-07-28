/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:17:42 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 12:29:56 by vrandria         ###   ########.fr       */
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
t_philo *ft_setup_philo(int id)
{
    t_philo *philo;
    
    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (0);
    philo->id = id;
    philo->eat_time = get_time();
    philo->nb_eat = 0;
    return (philo);
}

t_data *ft_setup(char *argv[])
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->time_start = get_time();
    data->nb_philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_steep = ft_atoi(argv[3]);
    data->time_stamp = 0;
    return (data);
}
int main(int argc, char *argv[])
{
    t_data *data;
    (void)argc;

    data = ft_setup(argv);
    printf("%d at %lu\n", data->nb_philo, data->time_start);
    ft_do_usleep(1000);
    printf("%d at %lu\n", data->nb_philo, data->time_start);
    free(data);
    return 0;
}
