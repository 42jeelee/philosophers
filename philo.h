/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:35:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/16 20:22:26 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_info
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_must_eat;
	pthread_mutex_t	info_key;
	pthread_mutex_t	printmu;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				eat_count;
	long long		lst_eat;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_info	*info;
}	t_philo;

int			info_init(t_info *info, int ac, char **av);
t_philo		*philo_init(t_info *info);

int			ft_power_atoi(char *str);
long long	get_now_time(void);

void		*fail_fork_init(t_philo *philos, int size);
int			fail_philo_init(t_info *info);

#endif