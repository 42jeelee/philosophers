/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:05:02 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/17 16:20:34 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_the_end(t_info *info)
{
	int	the_end;

	pthread_mutex_lock(&info->endmu);
	the_end = info->the_end;
	pthread_mutex_unlock(&info->endmu);
	return (the_end);
}

void	is_ending(t_info *info)
{
	pthread_mutex_lock(&info->endmu);
	info->the_end = 1;
	pthread_mutex_unlock(&info->endmu);
}

void	im_full(t_info *info)
{
	pthread_mutex_lock(&info->info_key);
	info->finished_philo += 1;
	if (info->finished_philo == info->philo_nb)
		is_ending(info);
	pthread_mutex_unlock(&info->info_key);
}
