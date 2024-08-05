/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/04 14:18:13 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>   
# include <unistd.h>
#include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h>
# include <pthread.h>
# include <errno.h>

# define LOCK 1
# define UNLOCK 2
# define INIT 3
# define DESTROY 4
# define JOIN 5
# define DETACH 6
# define CREATE 7

typedef struct s_data t_data;

typedef struct s_forks
{
    pthread_mutex_t fork;
    int fork_id;

}t_forks;

typedef struct s_philo
{
    int id;
    uint64_t    eat_count;
    uint64_t is_eat_max;
    uint64_t    last_eat;
    t_forks  *left_fork;
    t_forks  *right_fork;
    pthread_t   thread_id;
    t_data *data;
} t_philo;

struct s_data
{
    uint64_t    nb_philo;
    uint64_t    time_to_die;
    uint64_t    time_to_eat;
    uint64_t    time_to_sleep;
    uint64_t    need_to_eat;
    uint64_t time_start;
    int end_simu;
    int theards_is_ready;
    t_forks *fork;
    t_philo *philo;
    pthread_mutex_t data_mutex;
};
/*************utils_time.c *************/
void time_update(t_data *data);
void    ft_do_usleep(uint64_t time);
uint64_t get_time(void);
/******** ft_utis.c ********/
int	    ft_atoi(char *str);
size_t	ft_strlen(char *s);
uint64_t	ft_atoint64(char *str);
void	error_print(char *error);
/**********check.c****************/
void    check_input(t_data *data, char *argv[]);
char    *valid_value(char *str);
int simualtion_ended(t_data *data);
/***********init.c**************************/
void    data_init(t_data *data);
void    philo_init(t_data *data);
void    use_this_forks(t_philo *philo, t_forks *forks,int id);
/***********alloc_helps*******************/
void	*do_malloc(size_t bytes);
void    alloc_mutex(pthread_mutex_t *mutex, int code);
void    alloc_pthread(pthread_t *pthread, void *(*f)(void *), 
    void *data, int code);
/*****************simulation.c*************************/
void    simulation_start(t_data *data);
void *simulation(void *data);
/**************lock_unlock_utils.c*********************/
void    set_unlock_mutex(pthread_mutex_t *mutex,int *dest, int code);
int get_unlock_mutex(pthread_mutex_t *mutex, int *value);
void    set_unlock_mutex_uint64(pthread_mutex_t *mutex,uint64_t *dest, int code);
uint64_t get_unlock_mutex_uint64(pthread_mutex_t *mutex, uint64_t *value);
/********************control.c*******************************/
void wait_till_theads_is_ready(t_data *data);
#endif
