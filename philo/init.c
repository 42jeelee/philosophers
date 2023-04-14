/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:12:59 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/14 19:44:41 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->key), NULL))
		return (-1);
	if (pthread_mutex_init(&(info->printmu), NULL))
		return (-1);
	info->forks = (pthread_mutex_t *)malloc(\
		sizeof(pthread_mutex_t) * (info->philo_nb));
	if (!info->forks)
		return (-1);
	i = -1;
	while (++i < info->philo_nb)
	{
		if (pthread_mutex_init(&((info->forks)[i]), NULL))
		{
			free(info->forks);
			return (-1);
		}
	}
	return (0);
}

int	info_init(t_info *info, int ac, char **av)
{
	info->philo_nb = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start_time = get_now_time();
	if (ac == 6)
	{
		info->each_philo_must_eat = ft_atoi(av[5]);
		if (info->each_philo_must_eat < 0)
			return (-1);
	}
	else
		info->each_philo_must_eat = -1;
	if (info->philo_nb <= 0 || info->time_to_die < 0 || \
		info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (-1);
	return (mutex_init(info));
}

t_philo	*philo_init(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * info->philo_nb);
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < info->philo_nb)
	{
		philos[i].id = i;
		philos[i].lst_eat = info->start_time;
		philos[i].eat_count = 0;
		philos[i].left = &((info->forks)[i]);
		philos[i].right = &((info->forks)[(i + 1) % info->philo_nb]);
		if (pthread_mutex_init(&(info->key), NULL))
		{
			free(philos);
			return (NULL);
		}
		philos[i].info = info;
	}
	return (philos);
}
