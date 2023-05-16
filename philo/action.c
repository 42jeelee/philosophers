/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:14:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/16 20:35:07 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->l_fork);
	philo->l_fork_data -= 1;
	print("has taken a fork", philo->id, info);
	if (info->philo_nb > 1)
	{
		pthread_mutex_lock(philo->r_fork);
		*(philo->r_fork_data) -= 1;
		print("has taken a fork", philo->id, info);
	}
	else
		tick_tock(info->time_to_die, info);
}

void	put_fork(t_philo *philo)
{
	philo->l_fork_data += 1;
	pthread_mutex_unlock(&philo->l_fork);
	*(philo->r_fork_data) += 1;
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo, t_info *info)
{
	print("is sleeping", philo->id, info);
	tick_tock(info->time_to_sleep, info);
}

void	thinking(t_philo *philo, t_info *info)
{
	print("is thinking", philo->id, info);
	if (!info->time_to_sleep)
		tick_tock(50, info);
}
