#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &n)
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(n._value);
    _value = getRawBits();
}

Fixed& Fixed::operator=(const Fixed &d)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(d._value);
    _value = getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}