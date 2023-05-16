/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:10:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/16 21:01:04 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo, t_info *info)
{
	if (philo_starved(philo, info))
	{
		sem_wait(info->f);
		print("has taken a fork", philo, info, 0);
		if (info->philo_nb > 1)
		{
			sem_wait(info->f);
			print("has taken a fork", philo, info, 0);
			print("is eating", philo, info, 0);
			philo->eat_count += 1;
			philo->lst_eat = get_now_time();
			tick_tock(info->time_to_eat, philo, info);
			sem_post(info->f);
		}
		else
			usleep(info->time_to_die);
		sem_post(info->f);
	}
}

void	sleeping(t_philo *philo, t_info *info)
{
	if (philo_starved(philo, info))
	{
		print("is sleeping", philo, info, 0);
		tick_tock(info->time_to_sleep, philo, info);
	}
}

void	thinking(t_philo *philo, t_info *info)
{
	if (philo_starved(philo, info))
		print("is thinking", philo, info, 0);
}
