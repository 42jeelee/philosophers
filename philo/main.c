/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:36:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/17 12:00:12 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!(ac == 5 || ac == 6))
		return (-1);
	if (info_init(&info, ac, av) == -1)
		return (-1);
	if (sit_the_philos(&info) == -1)
	{
		final_info_destroy(&info);
		return (-1);
	}
	final_info_destroy(&info);
	return (0);
}
