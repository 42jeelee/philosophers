/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:17:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/16 22:47:14 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	am_i_starve(t_philo *philo, t_info *info)
{
	int			status;
	long long	now;

	pthread_mutex_lock(&philo->philo_key);
	now = get_now_time();
	if (now - philo->lst_eat >= info->time_to_die)
	{
		print("died", philo->id, info);
		is_ending(info);
	}
	pthread_mutex_unlock(&philo->philo_key);
}

void	eat_spaghetti(t_philo *philo, t_info *info)
{
	take_fork(philo, info);
	print("is eating", philo->id, info);
	pthread_mutex_lock(&philo->philo_key);
	philo->lst_eat = get_now_time();
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->philo_key);
	tick_tock(info->time_to_eat, info);
	put_fork(philo, info);
}

void	*ft_philosopher(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = arg;
	info = philo->info;
	while (!get_the_end(info))
	{
		if (am_i_starve(philo, info))
		{
			eat_spaghetti(philo, info);
			if (philo->eat_count == info->each_must_eat)
				is_ending(info);
			sleeping(philo, info);
			print("is thinking", philo->id, info);
		}
	}
}

int	sit_the_philos(t_info *info)
{
	t_philo	*philos;

	philos = philo_init(info);
	if (!philos)
		return (fail_philo_init(info));
}
