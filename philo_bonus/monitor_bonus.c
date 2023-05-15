/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:00 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/15 21:22:46 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*everyone_is_full(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *)arg;
	i = -1;
	while (++i < info->philo_nb)
		sem_wait(info->full);
	sem_post(info->e);
	return (NULL);
}

void	all_kill(t_philo *philos, t_info *info, int retno)
{
	int	i;

	i = -1;
	while (++i < info->philo_nb)
		kill(philos[i].pid, SIGINT);
	exit(retno);
}

void	who_is_died(t_philo *philos, t_info *info)
{
	sem_wait(info->e);
	all_kill(philos, info, 0);
}

void	observers(t_philo *philos, t_info *info)
{
	pthread_t	is_full;

	if (pthread_create(&is_full, NULL, everyone_is_full, info))
		exit(1);
	who_is_died(philos, info);
	if (pthread_join(is_full, NULL))
		exit(1);
}

int	philo_starved(t_philo *philo, t_info *info)
{
	if (get_now_time() - philo->lst_eat >= info->time_to_die)
	{
		sem_post(info->e);
		return (0);
	}
	return (1);
}
