/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:18:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/16 18:04:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(char *str)
{
	long long	n;

	n = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (n >= 214748365)
			return (-1);
		n = (n * 10) + *str - '0';
		str++;
	}
	if (n > 2147483647)
		return (-1);
	return (n);
}

int	ft_power_atoi(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(('0' <= str[i] && str[i] <= '9')))
			return (-1);
	}
	return (ft_atoi(str));
}

long long	get_now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print(char *msg, t_philo *philo, t_info *info)
{
	sem_wait(info->p);
	printf("%lld %d %s\n", get_now_time() - info->start_time, philo->id, msg);
	sem_post(info->p);
}

void	tick_tock(int ms, t_philo *philo, t_info *info)
{
	long long	start;
	long long	now;

	start = get_now_time();
	while (philo_starved(philo, info))
	{
		now = get_now_time();
		if (now - start >= ms)
			break ;
		usleep(500);
	}
}
