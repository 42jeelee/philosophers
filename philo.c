/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:17:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/16 20:18:54 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sit_the_philos(t_info *info)
{
	t_philo	*philos;

	philos = philo_init(info);
	if (!philos)
		return (fail_philo_init(info));
}
