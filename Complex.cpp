#include "Complex.hpp"
using namespace std;

Complex::Complex(double re , double im ){
    real = re;
    imag = im;
}
 
double Complex::get_real() const{
    return real;
}

double Complex::get_imag() const{
    return imag;
}

bool Complex::operator>(const Complex &other) const{
    return (real > other.get_real()) || (real == other.get_real() && imag > other.get_imag());
}
