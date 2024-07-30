#include <iostream>

class FixedPoint {
public:
    // Constant for fractional bits
    static constexpr int FRACTIONAL_BITS = 8;
    static constexpr int FIXED_POINT_SCALE = 1 << FRACTIONAL_BITS;

    // Constructor from integer
    explicit FixedPoint(int value) : value_(value * FIXED_POINT_SCALE) {}

    // Constructor from floating-point
    explicit FixedPoint(double value) : value_(value * FIXED_POINT_SCALE) {}

    // Convert to floating-point
    float toFloat() const {
        return value_ / FIXED_POINT_SCALE;
    }

    // Convert to integer
    int toInt() const {
        return value_ / FIXED_POINT_SCALE;
    }

private:
    int value_;
};

int main()
{
    FixedPoint fp1(10);
    FixedPoint fp2(42.42f);
    
    std::cout << fp1.toFloat() << std::endl;
    std::cout << fp2.toInt() << std::endl;
    return 0;
}
