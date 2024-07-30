#pragma once

#include <iostream>
#include <string>
#include <cmath>

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
};

std::ostream& operator<<(std::ostream& s , const Fixed& other);
