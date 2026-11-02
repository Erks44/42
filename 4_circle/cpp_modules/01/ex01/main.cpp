#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie* zombies = zombieHorde(N, "Bob");

    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;

    return (0);
}
