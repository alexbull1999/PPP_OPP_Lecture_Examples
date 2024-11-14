#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class SafeArray {
private:
  T *data;
  int length;
public:
  SafeArray(int items) {
    length = items;
    data = new T[length];
  }
  ~SafeArray() {
    delete [] data;
  }

  T & operator[] (int index) {
    if (index < 0 || index >= length) {
      cerr << "Index " << index << " out of bounds..." << endl;
      exit(1);
    }
    return data[index];
  }

  friend ostream &operator<< (ostream &out, const SafeArray<T> &s) {
    out << "[ ";
    for (int n=0; n<s.length; n++)
      out << s.data[n] << " ";
    out << "]";
    return out;
  }
};

int main() {

  SafeArray<double> x(10);

  SafeArray<char> y(20);

  for (int n=0; n<10; n++)
    x[n] = 2*n;
  /* x.operator[](n) = ... */

  cout << x << endl;

  x[5] = 6;
  //  x.operator[](5)

  cout << x[5] << endl;

  x[-2] = 7;

  return 0;
}
