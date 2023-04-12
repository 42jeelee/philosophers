/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:12:59 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/12 18:39:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->printmu), NULL))
		return (-1);
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (info->philo_nb));
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
		info->each_philo_must_eat = ft_atoi(av[5]);
	if (info->philo_nb <= 0 || info->time_to_die < 0 || \
		info->time_to_eat < 0 || info->time_to_sleep < 0 || info->each_philo_must_eat < 0)
		return (-1);
	return (mutex_init(info));
}
