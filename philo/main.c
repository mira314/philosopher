/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:54:17 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/03 17:57:45 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

 int main(int argc, char *argv[])
 {
    t_data data;
    if (argc == 5 || argc == 6)
    {
        check_input(&data, argv);
      //  data_init(&data);
       // start_simu(&data);
       // free_data(&data);
    }
    else
    { 
       error_print("argument invalid");
    }
    return 0;
 }
 