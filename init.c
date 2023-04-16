/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:45:21 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/16 20:24:36 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	info_init(t_info *info, int ac, char **av)
{
	memset(&info, 0, sizeof(t_info));
	info->philo_nb = ft_power_atoi(av[1]);
	info->time_to_die = ft_power_atoi(av[2]);
	info->time_to_eat = ft_power_atoi(av[3]);
	info->time_to_sleep = ft_power_atoi(av[4]);
	if (info->philo_nb <= 0 || info->time_to_die < 0 || \
		info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (-1);
	if (ac == 6)
	{
		info->each_must_eat = ft_power_atoi(av[5]);
		if (info->each_must_eat < 0)
			return (-1);
	}
	if (pthread_mutex_init(&info->info_key, NULL))
		return (-1);
	if (pthread_mutex_init(&info->printmu, NULL))
	{
		pthread_mutex_destroy(&info->info_key);
		return (-1);
	}
	return (0);
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
		philos[i].id = id + 1;
		philos[i].eat_count = 0;
		philos[i].lst_eat = get_now_time();
		if (pthread_mutex_init(&(philos[i].l_fork), NULL))
			return (fail_fork_init(philos, i));
		philos[i].r_fork = philos[(i + 1) % info->philo_nb].l_fork;
		philos[i].info = info;
	}
	return (philos);
}
