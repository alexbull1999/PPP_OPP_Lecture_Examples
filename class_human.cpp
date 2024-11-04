#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Human {
private:
  string name;
  int age;
  bool alive;
public:
  Human(string n, int a);
  virtual void have_birthday();
  string get_name() const { return name; };
  int get_age() const;
};

class TennisPlayer : public Human {
private:
  int ranking;
public:
  bool play_match_against(TennisPlayer *other);
  void have_birthday() {
    //    ...
  }
};

int Human::get_age() const {
  return age;
}


Human::Human(string n, int a) {
  name = n;
  age = a;
  alive = (age < 120);
}

void Human::have_birthday() {
  if (!alive)
    return;
  cout << "(" << this << ") happy birthday!" << endl;
  age++;
  if (age > 120)
    alive = false;
}

int main() {

  Human will("Will", 50);

  cout << will.get_name() << " is " << will.get_age() << " years old."<< endl;
  cout << will.get_name() << " lives on the stack at " << &will << endl;

  will.have_birthday();

  cout << will.get_name() << " is " << will.get_age() << " years old."<< endl;

  Human *alice = new Human ("Alice", 25);
  assert(alice);

  cout << "Alice lives on the heap at " << alice << endl;
  cout << "Alice is " << alice->get_age() << " years old." << endl;
  alice->have_birthday();
  cout << "Alice is " << (*alice).get_age() << " years old." << endl;

  delete alice;

  return 0;
}

