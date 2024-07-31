#include <iostream>
#include <string>

class Fixed
{
    private:
        int _value;
        static const int _fractBits = 8;

    public:
        Fixed();
        Fixed (const Fixed &n); 
        Fixed &operator=(const Fixed &d);
        ~Fixed();
         
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed(const int n);
        Fixed(const float n);
        int toInt(void) const;
        float toFloat(void) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
};

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

// std::ostream&  operator<<(std::ostream& s , const Fixed& other)
// {
//     s << other.toFloat();
//     return s;
// }

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(_value + other.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    
    res.setRawBits( (_value * other.getRawBits()) >> _fractBits);
    return res;
}

std::ostream& operator<<(std::ostream& s , Fixed& other)
{
    s << other.toFloat();
    return s;
}

int main()
{
    Fixed a = Fixed(4.4f);
    Fixed c;
    Fixed d;
    Fixed e;

    c = Fixed(5.4f);

    d = a + c;

    e = a * c;

    std::cout << a ;
    // std::cout << "this is a " <<a << std::endl;
    // std::cout << "this is c " <<c << std::endl;
    // std::cout << "this is d " <<d << std::endl;
    // std::cout << "this is e " <<e << std::endl;

    return 0;
}