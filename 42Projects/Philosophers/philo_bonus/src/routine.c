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
	sem_wait(philo->forks);  // Wait for access to the first fork
	print_message("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		sem_post(philo->forks);
		return ;
	}
	sem_wait(philo->forks);  // Wait for access to the second fork
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	sem_wait(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	sem_post(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	sem_post(philo->forks);  // Release the first fork
	sem_post(philo->forks);  // Release the second fork
}
