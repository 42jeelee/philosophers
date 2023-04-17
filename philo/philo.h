/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:35:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/17 12:03:36 by jeelee           ###   ########.fr       */
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
	int				finished_philo;
	int				the_end;
	long long		start_time;
	pthread_mutex_t	info_key;
	pthread_mutex_t	printmu;
	pthread_mutex_t	endmu;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				eat_count;
	long long		lst_eat;
	pthread_mutex_t	philo_key;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_info	*info;
}	t_philo;

int			info_init(t_info *info, int ac, char **av);
t_philo		*philo_init(t_info *info);

int			get_the_end(t_info *info);
void		is_ending(t_info *info);

int			sit_the_philos(t_info *info);

int			ft_power_atoi(char *str);
long long	get_now_time(void);
void		tick_tock(int ms, t_info *info);
void		print(char *msg, int id, t_info *info);

void		take_fork(t_philo *philo, t_info *info);
void		put_fork(t_philo *philo);
void		sleeping(t_philo *philo, t_info *info);

void		*fail_fork_init(t_philo *philos, int size);
int			fail_philo_init(t_info *info);
void		final_info_destroy(t_info *info);
void		final_philo_destroy(t_philo *philos, t_info *info);

#endif
