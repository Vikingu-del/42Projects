#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/wait.h>

/* errors */
# define WRONG_NUM_ARGS "❌ Error: Wrong number of arguments"
# define WRONG_ARG_TYPE "❌ Error: Numeric arguments required"
# define NUM_PHILO "❌ Error: Number of philosophers must be at least 1"
# define DIE_TIME "❌ Error: Time to die must be at least 1"
# define EAT_TIME "❌ Error: Time to eat must be at least 1"
# define SLEEP_TIME "❌ Error: Time to sleep must be at least 1"
# define NUM_EAT "❌ Error: Number of times to eat must be at least 1"
# define MALLOC_FAIL "❌ Error: Malloc failed"
# define THREAD_CREATE_FAIL "❌ Error: Thread create failed"
# define THREAD_JOIN_FAIL "❌ Error: Thread join failed"
# define MUTEX_FAIL "❌ Error: Mutex failed"
# define TIME_FAIL "❌ Error: Time failed"
# define FORK_FAIL "❌ Error: Fork failed"
# define JOIN_FAIL "❌ Error: Join failed"
# define UNLOCK_FAIL "❌ Error: Unlock failed"
# define LOCK_FAIL "❌ Error: Lock failed"
# define MALLOC_FAIL "❌ Error: Malloc failed"

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_data;

// utils.c
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_is_all_digits(char *str);
size_t	ft_strlen(const char *s);
int		ft_usleep(size_t time);

// check_valid_input.c
int	check_valid_input(int argc, char *argv[]);

// init.c
t_data	*init_data_mutexes(t_philo *philos);
void	destroy_data(char *str, t_data *data, pthread_mutex_t *forks);
void	init_philos(t_philo *philos, pthread_mutex_t *forks, t_data *data, char *argv[]);
void	parse_input(t_philo *philos, char *argv[]);
int		create_threads(t_data *data, pthread_mutex_t *forks);
void	init_forks(pthread_mutex_t *forks, int num_of_philos);

// custom.c
size_t	gettimeofday_custom(void);

// threads.c
int	dead_loop(t_philo *philo);
int	create_threads(t_data *data, pthread_mutex_t *forks)

// monitor.c
void	display_message(char *str, t_philo *philo);
int		check_if_all_ate(t_philo *philos);
int		time_to_die(t_philo *philo, size_t time_to_die);
int		check_if_dead(t_philo *philos);
void	*monitor(void *arg);

// routine.c
void	think_routine(t_philo *philo);
void	sleep_routine(t_philo *philo);
void	eat_routine(t_philo *philo);
void	*routine(void *arg);


#endif
