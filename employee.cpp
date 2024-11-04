#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
  double salary;
  string name;
protected:
  virtual double get_payrise_amount() = 0;
public:
  Employee(string n, double s) : name(n), salary(s) {
  }
  void get_payrise() {
    salary += get_payrise_amount();
  }
  friend ostream &operator<<(ostream &out, const Employee &empl);
};

ostream &operator<<(ostream &out, const Employee &empl) {
  out << "Employee " << empl.name << " with salary " << empl.salary;
  return out;
}

class Executive : public Employee {
  static double EXECUTIVE_PAYRISE_AMOUNT;
private:
  double get_payrise_amount() { return EXECUTIVE_PAYRISE_AMOUNT; }
public:
  Executive(string n, double s) : Employee(n,s) {
  }
};

class Manager : public Employee {
private:
  double get_payrise_amount() { return 100; }
public:
  Manager(string n, double s) : Employee(n,s) {
  }

};

double Executive::EXECUTIVE_PAYRISE_AMOUNT = 300;

int main() {

  Employee *staff[2];

  staff[0] = new Executive("Monty", 5000);
  staff[1] = new Manager("Waylon", 2000);

  for (int n=0; n<2; n++) {
    cout << *staff[n] << endl;
    staff[n]->get_payrise();
    cout << *staff[n] << endl;
  }

  /*
  cout << burns << endl;  //    operator<<(cout, burns)
  cout << smithers << endl;

  burns.get_payrise();
  smithers.get_payrise();

  cout << burns << endl;
  cout << smithers << endl;
  */

  return 0;
}

