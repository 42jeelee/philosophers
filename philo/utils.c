/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:46:17 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/13 19:00:13 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	n;
	int	m;

	n = 0;
	m = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * m);
}

long long	get_now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	print(char *msg, int id, t_info *info)
{
	long long	now;

	now = get_now_time();
	pthread_mutex_lock(&info->printmu);
	if (!info->end)
		printf("%lldms\t%d\t%s\n", \
			now - info->start_time, id + 1, msg);
	pthread_mutex_unlock(&info->printmu);
}

void	tick_tock(int ms, t_info *info)
{
	long long	now;

	while (!info->end)
	{
		now = get_now_time();
		if (now - info->start_time >= ms)
			break ;
		usleep(10);
	}
}
