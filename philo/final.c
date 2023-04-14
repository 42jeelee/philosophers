/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:01:24 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/12 19:05:03 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finalization_info(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&(info->printmu));
	i = -1;
	while (++i < info->philo_nb)
		pthread_mutex_destroy(&((info->forks)[i]));
	free(info->forks);
}
