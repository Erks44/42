#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== TEST 1 : CONSTRUCTEUR ===" << std::endl;
    ClapTrap bob("Bob");

    std::cout << "\n=== TEST 2 : ATTAQUE ===" << std::endl;
    bob.attack("Kevin");

    std::cout << "\n=== TEST 3 : DEGATS ===" << std::endl;
    bob.takeDamage(3);
    bob.takeDamage(4);

    std::cout << "\n=== TEST 4 : REPARATION ===" << std::endl;
    bob.beRepaired(5);

    std::cout << "\n=== TEST 5 : DEGATS MORTELS ===" << std::endl;
    bob.takeDamage(100);

    std::cout << "\n=== TEST 6 : ACTIONS SANS VIE ===" << std::endl;
    bob.attack("Kevin");
    bob.beRepaired(10);

    std::cout << "\n=== TEST 7 : ENERGIE EPUISEE ===" << std::endl;
    ClapTrap alice("Alice");

    for (int i = 0; i < 10; i++)
        alice.attack("Enemy");

    alice.attack("Enemy");
    alice.beRepaired(5);

    std::cout << "\n=== TEST 8 : DESTRUCTEURS ===" << std::endl;

    return 0;
}
