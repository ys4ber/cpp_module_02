#include "Fixed.hpp"


Fixed::Fixed()
{
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

