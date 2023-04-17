/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:14:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/17 18:43:38 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->l_fork);
	print("has taken a fork", philo->id, info);
	pthread_mutex_lock(philo->r_fork);
	print("has taken a fork", philo->id, info);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo, t_info *info)
{
	print("is sleeping", philo->id, info);
	tick_tock(info->time_to_sleep, info);
}
