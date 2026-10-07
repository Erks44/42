#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

bool Contact::setContact()
{
    std::cout << "First name: ";
    if (!std::getline(std::cin, firstName) || firstName.empty())
        return false;

    std::cout << "Nickname: ";
    if (!std::getline(std::cin, nickname) || nickname.empty())
        return false;

    std::cout << "Phone number: ";
    if (!std::getline(std::cin, phoneNumber) || phoneNumber.empty())
        return false;

    std::cout << "Darkest secret: ";
    if (!std::getline(std::cin, darkestSecret) || darkestSecret.empty())
        return false;
    return true;
}

void Contact::displayContact() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}
