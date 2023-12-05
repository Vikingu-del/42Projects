#include "philo_bonus.h"

// Think routine funtion

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

// Dream routine funtion

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

// Eat routine funtion

void	eat(t_philo *philo)
{
	sem_wait(philo->forks);
	if (philo->num_of_philos == 1)
	{
		print_message("has taken a fork", philo, philo->id);
		ft_usleep(philo->time_to_die);
		sem_post(philo->forks);
		return ;
	}
	sem_wait(philo->forks);
	print_message("has taken 2 forks", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	sem_wait(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	sem_post(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	sem_post(philo->forks);
	sem_post(philo->forks);
}
