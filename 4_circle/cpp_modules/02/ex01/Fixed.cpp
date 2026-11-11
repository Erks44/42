#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->value_number = other.value_number;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->value_number = other.value_number;
	std::cout << "Copy assignment operator called" << std::endl;
	return(*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->value_number);
}

void Fixed::setRawBits(int const raw)
{
	this->value_number = raw;
}

Fixed::Fixed(const int nb)
{
	this->value_number = nb * 256;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
	this->value_number = roundf(nb * 256);
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return(this->value_number / 256.0f);
}

int Fixed::toInt(void) const
{
	return(this->value_number / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return(os);
}
