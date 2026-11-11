#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value_number = 0;
}

Fixed::Fixed(const Fixed& other)
{
	this->value_number = other.value_number;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->value_number = other.value_number;
	return(*this);
}

int Fixed::getRawBits(void) const
{
	return(this->value_number);
}

void Fixed::setRawBits(int const raw)
{
	this->value_number = raw;
}

Fixed::Fixed(const int nb)
{
	this->value_number = nb * 256;
}

Fixed::Fixed(const float nb)
{
	this->value_number = roundf(nb * 256);
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

bool Fixed::operator>(const Fixed& other) const
{
    return (this->value_number > other.value_number);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->value_number < other.value_number);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->value_number >= other.value_number);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->value_number <= other.value_number);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->value_number == other.value_number);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->value_number != other.value_number);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed tmp;
	tmp.value_number = this->value_number + other.value_number;
	return(tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed tmp;
	tmp.value_number = this->value_number - other.value_number;
	return(tmp);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed tmp;
	tmp.value_number = this->value_number * other.value_number / 256;
	return(tmp);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed tmp;
	tmp.value_number = this->value_number * other.value_number / 512;
	return(tmp);
}

Fixed& Fixed::operator++()
{
	this->value_number++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value_number++;
	return(tmp);
}

Fixed& Fixed::operator--()
{
	this->value_number--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value_number--;
	return(tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a.value_number < b.value_number)
		return(a);
	else
		return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a.value_number < b.value_number)
		return(a);
	else
		return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a.value_number > b.value_number)
		return(a);
	else
		return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a.value_number > b.value_number)
		return(a);
	else
		return(b);
}
