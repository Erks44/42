#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Ebouvy");
    zombie->announce();
    delete zombie;

    randomChump("Billal");
    return(0);
}
