/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:42:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/14 21:38:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_philo_must_eat;
	long long		start_time;
	int				end;
	int				finished_eat;
	pthread_mutex_t	key;
	pthread_mutex_t	printmu;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		lst_eat;
	int				eat_count;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	key;
	struct s_info	*info;
}	t_philo;

int			sit_the_philo(t_info *info);

int			info_init(t_info *info, int ac, char **av);
t_philo		*philo_init(t_info *info);

int			ft_atoi(char *str);
int			get_end(t_info *info);
long long	get_now_time(void);
void		print(char *msg, int id, t_info *info);
void		tick_tock(int ms, t_info *info);
void		finalization_info(t_info *info, t_philo *philo);

#endif
