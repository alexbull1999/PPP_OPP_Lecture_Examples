#include <iostream>

using namespace std;

class ComplexNumber {

private:
  double re, im;

public:
  ComplexNumber() {
    cout << "default constructor (" << this << ")" << endl;
    re = im = 0;
  }

  ComplexNumber(double r, double i) : re(r), im(i) {
    cout << "constructor (" << this << ")" << endl;
  }

  ComplexNumber(const ComplexNumber &other) : re(other.re), im(other.im) {
    cout << "copy constructor (" << this << ")" << endl;
  }

  // unary -
  ComplexNumber operator-() {
    cout << "operator - (unary)" << endl;
    return ComplexNumber(-re, -im);
  }
  
    // binary -
  ComplexNumber operator-(const ComplexNumber &other) {
    cout << "operator - (binary)" << endl;
    ComplexNumber result(re-other.re, im-other.im);
    return result;
  }

  ComplexNumber operator+(const ComplexNumber &other) {
    cout << "operator +" << endl;
    ComplexNumber result(re+other.re, im+other.im);
    return result;
  }

  ComplexNumber add(const ComplexNumber &other) {
    cout << "add" << endl;
    ComplexNumber result(re+other.re, im+other.im);
    return result;
  }

  friend ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b\
) {
    return ComplexNumber(a.re+b.re-a.im*b.im, a.re*b.im+a.im*b.re);
  }

  friend ostream &operator<<(ostream &out, const ComplexNumber &object) {
    out << "(" << object.re << (object.im >= 0 ? "+" : "") << object.im << "i)"\
;
    return out;
  }

};

int main() {
  ComplexNumber a(1,1), b(2,2), c;

  c = a + b;  // c = a.operator+(b) // c.operator=(...)
  // a = b = c = d;
  cout << "a = " << a << endl;
  cout << "-a = " << -a << endl; //a.operator-()

  cout << "a-b = " << a - b << endl; //a.operator-(b)

  cout << b << endl; // cout.operator<<(b) <-- lookup fails
                     // operator<<(cout, b); <-- lookup succeeds
  cout << "c = " << a + b << endl;

  cout << a.add(b) << endl;

  c = a * b; // a.operator*(b); <-- lookup fails
             // operator*(a,b); <-- lookup succeeds
}

