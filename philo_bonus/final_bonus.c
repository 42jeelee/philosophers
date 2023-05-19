/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:15 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/19 16:16:38 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	final_info(t_info *info)
{
	sem_close(info->f);
	sem_close(info->p);
	sem_close(info->full);
}

void	final_philos(t_philo *philos)
{
	free(philos);
}
