#include <string>
#include <iostream>

int main()
{
    int a = 25;
    std::string age;
    std::string prenom = "Ebouvy";
    std::cout << prenom << " il a " << a << "?" << std::endl;
    std::getline(std::cin, age);
    std::cout << prenom << " il a " << a << age << std::endl;
    return (0);
}
