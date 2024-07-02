
#include <iostream>
#include <string>

class Complex
{
    double real, imag;

public:
    Complex(double real, double image);
    double get_real() const;

    double get_imag() const;

    bool operator>(const Complex &other) const;

    friend bool operator==(const Complex &a, const Complex &b){
        return (a.get_real() == b.get_real() && a.get_imag() == b.get_imag());
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c){
        os << c.get_real() << " + " << c.get_imag() << "i";
        return os;
    }

};
