/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:00 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/19 16:21:20 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	all_kill(t_philo *philos, t_info *info, int retno)
{
	int	i;

	i = -1;
	while (++i < info->philo_nb)
		kill(philos[i].pid, SIGINT);
	exit(retno);
}

void	*everyone_is_full(void *arg)
{
	t_philo	*philos;
	t_info	*info;
	int		i;

	philos = (t_philo *)arg;
	info = philos[0].info;
	i = -1;
	while (++i < info->philo_nb)
		sem_wait(info->full);
	all_kill(philos, info, 0);
	return (NULL);
}

void	who_is_died(t_philo *philos, t_info *info)
{
	int	status;

	waitpid(-1, &status, 0);
	all_kill(philos, info, status);
}

void	observers(t_philo *philos, t_info *info)
{
	pthread_t	is_full;

	if (pthread_create(&is_full, NULL, everyone_is_full, philos))
		all_kill(philos, info, 1);
	who_is_died(philos, info);
	if (pthread_join(is_full, NULL))
		all_kill(philos, info, 1);
}

void	*philo_starved(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	while (get_now_time() - philo->lst_eat < info->time_to_die)
		;
	print("died", philo, info, 1);
	exit(0);
	return (NULL);
}
