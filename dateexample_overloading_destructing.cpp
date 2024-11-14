#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Date {
private:
  int day,month,year;

public:

  Date() {
     cout << "Date(" << this << ") default constructor" << endl;
     day = 1; month = 1; year = 2000;
  }

  Date(int d, int m, int y);

  Date &operator=(const Date &other) {
    cout << "Date(" << this << ") assignment operator" << endl;
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
  }

    Date(const Date &other) {
    cout << "Date(" << this << ") copy constructor" << endl;

    day = other.day;
    month = other.month;
    year = other.year;
  }

  ~Date() {
    cout << "Date(" << this << ") destructor" << endl;
  }

  //  bool equal(const Date &other) const;

  bool operator==(const Date &other) const {
    return (day == other.day && month == other.month && year==other.year);
  }

  bool operator< (const Date &other) const {

    if (year < other.year)
      return true;
    if (year > other.year)
      return false;
    if (month < other.month)
      return true;
    if (month > other.month)
      return false;
    return (day < other.day);

    //    return toSecondsSince1970() < other.toSecondsSince1970();
    return false;
  }

  friend ostream &operator<< (ostream &out, const Date &d);
};

ostream &operator<< (ostream &out, const Date &d) {
  out << d.day << "/" << d.month << "/" << d.year;
  return out;
}

Date::Date(int d, int m, int y)
{
  day = d; month=m; year=y;
  cout << "Date(" << this << ") constructor" << endl;
}

void print_day(Date &day) {
  cout << "printing date at address " << &day << endl;
}

int main() {

  Date one(11,11,2024), two(11,11,2024), three;

  cout << "one = " << one << endl;
  cout << "two = " << two << endl;
  cout << "three = " << three << endl;

  if (one == two) {   // one.operator==(two)    operator==(one,two)
    cout << "SAME!" << endl;
  } else {
    cout << "NOT!" << endl;
  }

  if (one < two) {
    // one.operator<(two)
    // operator<(one,two)
    cout << "one is less than two!" << endl;
  } else {
    cout << "one is not less than two!" << endl;
  }

  return 0;

}

