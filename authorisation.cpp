#include <iostream>
#include <string>
#include <list>

using namespace std;

class Directory {
private:
  string name;
  Directory *parent;
public:
  // constructor
  Directory(string n, Directory *p) : name(n), parent(p) {
  }
  // copy constructor
  Directory(const Directory &d) : name(d.name), parent(d.parent) {
  }
};

class User {
private:
  string login;
};

class Session {
public:
  // default constructor
  Session() {
  }
  // copy constructor
  Session(const Session &s) {
  }
};

class Authorisation;

class Workstation {
private:
  string hostname;
  list <Authorisation *> authorisations;
public:
  Workstation(string h) : hostname(h) {
  }
};

class Authorisation {
private:
  User *user;
  Workstation *workstation;
  int priority;
  Session start_session;
  Directory *default_directory;
public:
  Authorisation(User *u, Workstation *w, int p, const Session &s, Directory *dd) : user(u), workstation(w), priority(p), start_session(s), default_directory(dd) {
  }
};

