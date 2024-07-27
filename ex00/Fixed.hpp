#pragma once

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &other);            // Copy constructor
        Fixed &operator=(const Fixed &other);
        int getRawBits(void) const;
        ~Fixed();
};