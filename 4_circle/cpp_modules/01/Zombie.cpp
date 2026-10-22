#include "Zombie.cpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed" << stdl::end;
}

void Zombie::anounce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
