/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:41:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/09 20:13:16 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!(ac == 5 || ac == 6))
		return (-1);
	memset(&info, 0, sizeof(t_info));
	if (info_init(&info, ac, av) == -1)
		return (-1);
	return (0);
}
