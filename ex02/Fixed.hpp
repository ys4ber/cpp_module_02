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

        // > < >= <= == != " operators
        int operator>(const Fixed &other) const;
        int operator<(const Fixed &other) const;
        int operator>=(const Fixed &other) const;
        int operator<=(const Fixed &other) const;
        int operator==(const Fixed &other) const;
        int operator!=(const Fixed &other) const;

        // " + - * / " operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;


        // " ++ -- " operators
            // prefix
        Fixed &operator++(void);
        Fixed &operator--(void);

            // postfix
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &min(Fixed const &a, Fixed const &b);

        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed &max(Fixed const &a, Fixed const &b);


};

std::ostream& operator<<(std::ostream& s , const Fixed& other);