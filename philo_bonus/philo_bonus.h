/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:00:55 by jeelee            #+#    #+#             */
/*   Updated: 2023/05/16 20:24:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

# define PHILO_FORK "philo_fork"
# define PRINT_SEM "print_sem"
# define END_SEM "end_sem"
# define FULL_SEM "full_sem"

typedef struct s_info
{
	int			philo_nb;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			each_must_eat;
	long long	start_time;
	sem_t		*f;
	sem_t		*p;
	sem_t		*e;
	sem_t		*full;
}	t_info;

typedef struct s_philo
{
	int			id;
	pid_t		pid;
	int			eat_count;
	int			died;
	long long	lst_eat;
}	t_philo;

int			sit_the_philos(t_info *info);

void		eating(t_philo *philo, t_info *info);
void		sleeping(t_philo *philo, t_info *info);
void		thinking(t_philo *philo, t_info *info);

void		all_kill(t_philo *philos, t_info *info, int retno);
void		observers(t_philo *philos, t_info *info);
int			philo_starved(t_philo *philo, t_info *info);

int			info_init(t_info *info, int ac, char **av);
t_philo		*philos_init(t_info *info);

int			ft_power_atoi(char *str);
void		print(char *msg, t_philo *philo, t_info *info);
void		tick_tock(int ms, t_philo *philo, t_info *info);
long long	get_now_time(void);

void		final_info(t_info *info);
void		final_philos(t_philo *philos);

#endif