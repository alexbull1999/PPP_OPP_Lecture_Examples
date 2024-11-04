#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Item;

class LibraryUser {
private:
  string name;
  Item *borrowed[3];
  int items_borrowed() {
    int items = 0;
    for (int n=0; n<3; n++)
      if (borrowed[n])
        items++;
    return items;
  }
public:
  LibraryUser(string n) : name(n) {
    for (int n=0; n<3; n++)
      borrowed[n] = NULL;
  };
  bool borrow(Item *target);
  bool give_back(Item *target);
};

class Item {
protected:
  string title;
  int location_no;
  LibraryUser *borrowed_by;
public:
  Item(string t, int ln) : title(t), location_no(ln), borrowed_by(NULL) {
  }
  virtual int get_loan_period() = 0;
  bool on_loan() const { return (borrowed_by != NULL); }
  LibraryUser *get_borrowed_by() const { return borrowed_by; }
  void set_borrowed_by(LibraryUser *user) {
    borrowed_by = user;
  }
  string get_title() const { return title; }
};

class Book : public Item {
  int loan_period;
public:
  Book(string t, int ln, int lp) : Item(t, ln), loan_period(lp) {
  }
  int get_loan_period() {
    return loan_period;
  }
};

class Periodical : public Item {
  static int loan_period;
public:
  Periodical(string t, int ln) : Item(t, ln) {
  }
  int get_loan_period() {
    return loan_period;
  }
  static void set_loan_period(int lp) {
    Periodical::loan_period = lp;
  }
};

int Periodical::loan_period = 5;

bool LibraryUser::borrow(Item *target) {
  if (target->on_loan())
    return false;
  if (items_borrowed() >= 3)
    return false;
  for (int n=0; n<3; n++) {
    if (borrowed[n] == NULL) {
      borrowed[n] = target;
      break;
    }
  }
  target->set_borrowed_by(this);
  cout << name << " borrows " << target->get_title() << " for " << target->get_\
loan_period() << " days" << endl;
  return true;
}

bool LibraryUser::give_back(Item *target) {
  for (int n=0; n<3; n++) {
    if (borrowed[n] == target) {
      assert(target->get_borrowed_by() == this);
      target->set_borrowed_by(NULL);
      borrowed[n] = NULL;
      cout << name << " returns " << target->get_title() << endl;
      return true;
    }
  }
  return false;
}

int main() {

  LibraryUser georgia("georgia"), ali("ali");

  Book lotr("Lord of the Rings", 1, 21);
  Periodical cb("Classic Boat", 2);

  if (georgia.borrow(&lotr))
    cout << "success!" << endl;
  else
    cout << "fail!" << endl;

  georgia.give_back(&lotr);

  if (ali.borrow(&lotr))
    cout << "success!" << endl;
  else
    cout << "fail!" << endl;

  Periodical::set_loan_period(14);
  ali.borrow(&cb);

  return 0;
}
