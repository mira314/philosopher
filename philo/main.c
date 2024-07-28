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
void time_update(t_data *data)
{
    uint64_t diff_time;

    diff_time = (get_time() - (data->time_start));
    data->time_stamp = (unsigned int)diff_time;
}
int main(int argc, char *argv[])
{
    t_data *data;
    (void)argc;

    data = ft_setup(argv);
    printf("%d at %d\n", data->nb_philo, data->time_stamp);
    usleep(10000);
    time_update(data);
    printf("%d at %d\n", data->nb_philo, data->time_stamp);
    free(data);
    return 0;
}
