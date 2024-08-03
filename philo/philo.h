/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/03 17:56:51 by vrandria         ###   ########.fr       */
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
# include <err.h>

# define LOCK 1
# define UNLOCK 2
# define INIT 3
# define DESTROY 4
# define JOIN 5
# define DETACH 6
# define CREATE 7

typedef struct s_data t_data;

enum e_pcode
{
    3
}
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
    t_forks *fork;
    t_philo *philo;
};

/******** ft_utis.c ********/
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
uint64_t	ft_atoint64(const char *str);
void	error_print(char *error);
/**********check.c****************/
void    check_input(t_data *data, char *argv[]);
char    *valid_value(char *str);
/***********init.c**************************/
void    data_init(t_data *data);
void    philo_init(t_data *data);
void use_this_forks(t_philo *philo, t_forks *forks,int id);
/***********alloc_helps*******************/
void	*do_malloc(size_t bytes);
void    alloc_mutex(pthread_mutex_t *mutex, int code);
void    alloc_pthread(pthread_t *pthread, void *(*f)(void *), 
    void *data, int code);


#endif
