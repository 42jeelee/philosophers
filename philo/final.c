/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:11:39 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/16 22:32:25 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fail_fork_init(t_philo *philos, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		pthread_mutex_destroy(&(philos[i]).l_fork);
		pthread_mutex_destroy(&(philos[i]).philo_key);
	}
	free(philos);
	return (NULL);
}

int	fail_philo_init(t_info *info)
{
	pthread_mutex_destroy(&info->info_key);
	pthread_mutex_destroy(&info->printmu);
	retrun (-1);
}
