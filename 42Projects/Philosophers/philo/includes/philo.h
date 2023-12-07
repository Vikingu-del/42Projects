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

# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

// Main functions
int					check_arg_content(char *arg);
int					check_valid_args(char **argv);
void				destory_all(char *str, t_program *program,
						pthread_mutex_t *forks);

// Initialization
void				init_program(t_program *program, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);

// Threads
int					thread_create(t_program *program, pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);

// Actions
void				eat(t_philo *philo);
void				dream(t_philo *philo);
void				think(t_philo *philo);

// Monitor utils
int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

// Utils
int					ft_atoi(char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

// put in fd
int					has_only_digits(char *s);
void				ft_putendl_fd(char *s, int fd);

#endif
