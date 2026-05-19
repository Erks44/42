*This project has been created as part of the 42 curriculum by egjika*

## Description
Philosophers represents the classic Dining Philosophers problem (Dijkstra).
The goal is to make philosophers eat, sleep and think without dying.
We learned to use POSIX threads and mutexes, and understood the risks
of data races, deadlocks and starvation.

## Instructions
```bash
make
./philo [nb_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [nb_times_eat]
```
Example:
```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```
To clean: `make clean` or `make fclean`

## Resources
- https://en.wikipedia.org/wiki/Dining_philosophers_problem
- https://man7.org/linux/man-pages/man3/pthread_create.3.html
- Claude AI was used to understand concepts of threads and mutexes,
  and to guide the logic of the implementation step by step.