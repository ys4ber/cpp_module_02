#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const Fixed &n)
{
    *this = n;
}

Fixed &Fixed::operator=(const Fixed &n)
{
    _value = n._value;
    return *this;
}

Fixed::~Fixed()
{
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
    _value = n << _fractBits;
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

std::ostream& operator<<(std::ostream& s , const Fixed& other)
{
    s << other.toFloat();
    return s;
}

int Fixed::operator>(const Fixed &other) const
{
    return (_value > other._value);
}

int Fixed::operator<(const Fixed &other) const
{
    return (_value < other._value);
}

int Fixed::operator>=(const Fixed &other) const
{
    return (_value >= other._value);
}

int Fixed::operator<=(const Fixed &other) const
{
    return (_value <= other._value);
}

int Fixed::operator==(const Fixed &other) const
{
    return (_value == other._value);
}

int Fixed::operator!=(const Fixed &other) const
{
    return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res._value = this->_value + other._value;
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    res._value = (this->_value * other._value ) / 256;
    // or res._value = (this->_value * other._value ) >> _fracBits;
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res._value = this->_value - other._value;
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    if (other._value == 0)
    {
        std::cout << "Error: Division by zero" << std::endl;
        return res;
    }
    res._value = (this->_value / other._value) * 256;
    // or res._value = (this->_value / other._value) << _fracBits;
    return res;
}

Fixed &Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed &Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++_value;
    return temp;

}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --_value ;
    return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
    {
        return (Fixed &)a;
    }
    return (Fixed &)b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
    {
        return (Fixed &)a;
    }
    return (Fixed &)b;
}
