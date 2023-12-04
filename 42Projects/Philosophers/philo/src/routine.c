#include "philo.h"

void	think_routine(t_philo *philo)
{
	write(1, "🤔", 1);
	display_message("is thinking", philo);
}

void	sleep_routine(t_philo *philo)
{
	write(1, "😴", 1);
	display_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write(1, "🍴", 1);
	display_message("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	write(1, "🍴", 1);
	display_message("has taken a fork", philo);
	philo->eating = 1;
	write(1, "🍝", 1);
	display_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = gettimeofday_custom();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->id % 2 == 0)
			ft_usleep(1);
		while (!dead_loop(philo))
		{
			eat_routine(philo);
			sleep_routine(philo);
			think_routine(philo);
		}
	}
	return (arg);

}