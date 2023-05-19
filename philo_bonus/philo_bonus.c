/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:29:16 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/19 16:26:12 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philosopher(t_philo *philo)
{
	pthread_t	reaper;
	t_info		*info;

	if (pthread_create(&reaper, NULL, philo_starved, philo))
		exit(1);
	info = philo->info;
	if (philo->id <= info->philo_nb / 2)
		tick_tock(info->time_to_eat / 2);
	while (1)
	{
		eating(philo, info);
		if (philo->eat_count == info->each_must_eat)
			sem_post(info->full);
		sleeping(philo, info);
		thinking(philo, info);
	}
	exit(0);
}

int	sit_the_philos(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = philos_init(info);
	if (!philos)
		return (1);
	i = -1;
	while (++i < info->philo_nb)
	{
		philos[i].pid = fork();
		if (philos[i].pid == -1)
			all_kill(philos, info, 1);
		else if (philos[i].pid == 0)
			ft_philosopher(&(philos[i]));
	}
	observers(philos, info);
	i = -1;
	while (++i < info->philo_nb)
		waitpid(philos[i].pid, 0, 0);
	final_philos(philos);
	return (0);
}
