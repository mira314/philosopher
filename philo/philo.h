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
   uint64_t	eat_last_time;

}t_philo;

typedef struct s_data
{
	int nb_philo;
	int nb_need_eat;
	int nb_fork;
	unsigned int    time_to_die;
	unsigned int     time_to_steep;
	unsigned int     time_to_eat;
	uint64_t    time_start;
	t_philo     *philo;
	pthread_mutex_t	*forks;
	unsigned int         time_stamp;
} t_data;

typedef struct s_threads
{
	int flag;
} t_threads;


 /******** utils_time.c   ********/
uint64_t	get_time(void);
int	ft_do_usleep(uint64_t time);
void	time_update(t_data *data);
/******** ft_utis.c ********/
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
uint64_t	ft_atol64(const char *str);
#endif