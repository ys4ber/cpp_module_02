#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &n)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = n;
}

Fixed &Fixed::operator=(const Fixed &n)
{
    std::cout << "Assignation operator called" << std::endl;
    _value = n._value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &s, const Fixed& other)
{
    s << other.toFloat();
    return s;
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

Fixed::Fixed(const int n)
{
    _value = n >> _fractBits;
}

Fixed::Fixed(const float n)
{
    _value = n * (1 << _fractBits);
}

int Fixed::toInt() const
{
    return (_value >> _fractBits);
}

float Fixed::toFloat() const
{
    return (_value / float(1 << _fractBits));
}