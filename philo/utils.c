/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:46:17 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/14 21:14:37 by jeelee           ###   ########.fr       */
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

int	get_end(t_info *info)
{
	int	end;

	pthread_mutex_lock(&(info->key));
	end = info->end;
	pthread_mutex_unlock(&(info->key));
	return (end);
}

long long	get_now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print(char *msg, int id, t_info *info)
{
	long long	now;

	now = get_now_time();
	pthread_mutex_lock(&info->printmu);
	if (!get_end(info))
		printf("%lldms\t%d\t%s\n", \
			now - info->start_time, id + 1, msg);
	pthread_mutex_unlock(&info->printmu);
}

void	tick_tock(int ms)
{
	long long	start;
	long long	now;

	start = get_now_time();
	while (1)
	{
		now = get_now_time();
		if (now - start >= ms)
			break ;
		usleep(10);
	}
}
