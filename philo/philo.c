/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:17:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/17 18:45:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_starved(t_philo *philos, t_info *info)
{
	int			i;
	long long	now;

	while (!get_the_end(info))
	{
		i = -1;
		while (++i < info->philo_nb)
		{
			pthread_mutex_lock(&(philos[i].philo_key));
			now = get_now_time();
			if (now - philos[i].lst_eat >= info->time_to_die)
			{
				print("died", philos[i].id, info);
				is_ending(info);
			}
			pthread_mutex_unlock(&(philos[i].philo_key));
		}
	}
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
	put_fork(philo);
}

void	*ft_philosopher(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = arg;
	info = philo->info;
	if (!(philo->id & 1) || \
		(info->philo_nb & 1 && philo->id == info->philo_nb))
	{
		print("is thinking", philo->id, info);
		tick_tock(info->time_to_eat, info);
	}
	while (!get_the_end(info))
	{
		eat_spaghetti(philo, info);
		if (philo->eat_count == info->each_must_eat)
		{
			im_full(info);
			break ;
		}
		sleeping(philo, info);
		print("is thinking", philo->id, info);
	}
	return (NULL);
}

int	sit_the_philos(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = philo_init(info);
	if (!philos)
		return (fail_philo_init(info));
	info->start_time = get_now_time();
	i = -1;
	while (++i < info->philo_nb)
		pthread_create(&(philos[i].thread), NULL, ft_philosopher, &(philos[i]));
	who_starved(philos, info);
	i = -1;
	while (++i < info->philo_nb)
		pthread_join(philos[i].thread, NULL);
	final_philo_destroy(philos, info);
	free(philos);
	return (0);
}
