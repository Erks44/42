#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

static std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

PhoneBook::PhoneBook()
{
    count = 0;
    nextIndex = 0;
}

void PhoneBook::addContact()
{
    Contact newContact;

    if (!newContact.setContact())
    {
        std::cout << "Invalid contact" << std::endl;
        return;
    }

    contacts[nextIndex] = newContact;

    nextIndex = (nextIndex + 1) % 8;

    if (count < 8)
        count++;

    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchContact() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname())
                  << std::endl;
    }

    std::cout << "Enter index: ";

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int index;
    char extra;

    if (!(ss >> index) || (ss >> extra) || index < 0 || index >= count)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    contacts[index].displayContact();
}