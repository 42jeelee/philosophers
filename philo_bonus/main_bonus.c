/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:00:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/15 16:45:26 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!(ac == 5 || ac == 6))
		return (-1);
	if (info_init(&info, ac, av) == -1)
		return (-1);
	if (sit_the_philos(&info) == -1)
	{
		final_info(&info);
		return (-1);
	}
	final_info(&info);
	return (0);
}
