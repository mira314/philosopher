/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:03:06 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/04 13:12:32 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void wait_till_theads_is_ready(t_data *data)
{
    while (!get_unlock_mutex(&data->data_mutex, data->theards_is_ready))
    ;
}