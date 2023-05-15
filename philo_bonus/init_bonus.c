/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:17:27 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/15 22:06:44 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_sem_init(t_info *info)
{
	info->f = sem_open(PHILO_FORK, O_CREAT, 0644, info->philo_nb);
	if (info->f == SEM_FAILED)
		exit(1);
	info->p = sem_open(PRINT_SEM, O_CREAT, 0644, 1);
	if (info->p == SEM_FAILED)
		exit(1);
	info->e = sem_open(END_SEM, O_CREAT, 0644, 0);
	if (info->e == SEM_FAILED)
		exit(1);
	info->full = sem_open(FULL_SEM, O_CREAT, 0644, 0);
	if (info->full == SEM_FAILED)
		exit(1);
	return (0);
}

int	info_init(t_info *info, int ac, char **av)
{
	memset(info, 0, sizeof(t_info));
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
	else
		info->each_must_eat = -1;
	return (philo_sem_init(info));
}

t_philo	*philos_init(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * info->philo_nb);
	if (!philos)
		return (NULL);
	info->start_time = get_now_time();
	i = -1;
	while (++i < info->philo_nb)
	{
		philos[i].id = i + 1;
		philos[i].pid = 0;
		philos[i].eat_count = 0;
		philos[i].lst_eat = info->start_time;
	}
	return (philos);
}
