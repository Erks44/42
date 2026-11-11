#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
		name(name), hit_points(10), energy(10), attacks_damage(0)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->energy > 0 && this->hit_points > 0)
	{
		this->energy -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing "<< this->attacks_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no more energy or hit points..." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hit_points > 0 && amount <= static_cast<unsigned int>(hit_points))
	{
		hit_points -= amount;
		std::cout << this->name << " lost " << amount << " points." << std::endl;
	}
	else if(hit_points > 0 && amount > static_cast<unsigned int>(hit_points))
	{
		int tmp = hit_points;
		hit_points -= hit_points;
		std::cout << this->name << " lost " << tmp << " points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(hit_points > 0 && energy >= 1)
	{
		hit_points += amount;
		energy -= 1;
		std::cout << this->name << " gained " << amount << " points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no more energy or hit points..." << std::endl;
}
