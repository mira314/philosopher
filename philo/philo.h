/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/07/28 13:49:02 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h>


typedef struct s_philo
{
   int		id;
   int		nb_eat;
   uint64_t	eat_time;

}t_philo;

typedef struct s_data
{
    int nb_philo;
    int nb_need_eat;
    int nb_fork;
    uint64_t    time_eat;
    uint64_t    time_to_die;
    uint64_t    time_to_steep;
    uint64_t    time_start;
    t_philo     *philosopher;
    unsigned int         time_stamp;
} t_data;

typedef struct s_threads
{
    int flag;
} t_threads;


 /******** utils_time.c   ********/
uint64_t    get_time(void);
int        ft_do_usleep(uint64_t time);
/******** ft_utis.c ********/
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
uint64_t	ft_atol64(const char *str);
#endif