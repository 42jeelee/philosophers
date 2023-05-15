/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:15 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/15 21:09:18 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	final_info(t_info *info)
{
	sem_close(info->f);
	sem_unlink(PHILO_FORK);
	sem_close(info->p);
	sem_unlink(PRINT_SEM);
	sem_close(info->e);
	sem_unlink(END_SEM);
	sem_close(info->full);
	sem_unlink(FULL_SEM);
}

void	final_philos(t_philo *philos)
{
	free(philos);
}
