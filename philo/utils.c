/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:47:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/15 12:52:03 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	tick_tock(int ms, t_info *info)
{
	long long	start;
	long long	now;

	start = get_now_time();
	while (!get_the_end(info))
	{
		now = get_now_time();
		if (now - start >= ms)
			break ;
		usleep(500);
	}
}

void	print(char *msg, int id, t_info *info)
{
	pthread_mutex_lock(&info->printmu);
	if (!get_the_end(info))
		printf("%lld %d %s\n", get_now_time() - info->start_time, id, msg);
	pthread_mutex_unlock(&info->printmu);
}
