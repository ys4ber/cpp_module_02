#pragma once

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
};