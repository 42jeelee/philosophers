/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:05:24 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/14 21:32:16 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	did_someone_die(t_philo *philos, t_info *info)
{
	int			i;
	long long	now;
	long long	lst_eat;

	while (!(info->end))
	{
		now = get_now_time();
		i = -1;
		while (++i < info->philo_nb)
		{
			pthread_mutex_lock(&(philos[i].key));
			lst_eat = philos[i].lst_eat;
			pthread_mutex_unlock(&(philos[i].key));
			if (now - lst_eat >= info->time_to_die)
			{
				print("died", philos[i].id, info);
				pthread_mutex_lock(&(info->key));
				info->end = 1;
				pthread_mutex_unlock(&(info->key));
				break ;
			}
		}
	}
}

void	fst_take_fork(pthread_mutex_t **fst, pthread_mutex_t **sec, \
	t_philo *philo)
{
	if (philo->id % 2)
	{
		*fst = philo->right;
		*sec = philo->left;
	}
	else
	{
		*fst = philo->left;
		*sec = philo->right;
	}
}

void	eating_spaghetti(t_philo *philo, t_info *info)
{
	pthread_mutex_t	*fst;
	pthread_mutex_t	*sec;

	fst_take_fork(&fst, &sec, philo);
	pthread_mutex_lock(philo->left);
	print("has taken a fork", philo->id, info);
	if (info->philo_nb > 1)
	{
		pthread_mutex_lock(philo->right);
		print("has taken a fork", philo->id, info);
		print("is eating", philo->id, info);
		pthread_mutex_lock(&(philo->key));
		philo->lst_eat = get_now_time();
		philo->eat_count += 1;
		pthread_mutex_unlock(&(philo->key));
		tick_tock(info->time_to_eat);
		pthread_mutex_unlock(philo->right);
	}
	else
		usleep(info->time_to_die);
	pthread_mutex_unlock(philo->left);
}

void	*ft_philosopher(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = arg;
	info = philo->info;
	if (philo->id % 2)
		usleep(100);
	while (!get_end(info))
	{
		eating_spaghetti(philo, info);
		if (philo->eat_count == info->each_philo_must_eat)
		{
			info->finished_eat++;
			if (info->finished_eat == info->philo_nb)
				info->end = 1;
			break ;
		}
		print("is sleeping", philo->id, info);
		tick_tock(info->time_to_sleep);
		print("is thinking", philo->id, info);
	}
	return (NULL);
}

int	sit_the_philo(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = philo_init(info);
	if (!philos)
		return (-1);
	i = -1;
	while (++i < info->philo_nb)
		pthread_create(&(philos[i].thread), NULL, \
			ft_philosopher, &(philos[i]));
	did_someone_die(philos, info);
	i = -1;
	while (++i < info->philo_nb)
		pthread_join(philos[i].thread, NULL);
	finalization_info(info, philos);
	free(philos);
	return (0);
}
