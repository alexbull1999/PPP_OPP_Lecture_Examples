#include <iostream>
#include <string>

using namespace std;

class RAM {
};

class CPU {
public:
  /* constructor */
  CPU() {
    cout << "CPU(" << this << ") constructing..." << endl;
  }
  /* destructor */
  ~CPU() {
    cout << "CPU(" << this << ") destructing..." << endl;
  }

};

class Chassis {
public:
  Chassis() {
    cout << "Chassis(" << this << ") constructing..." << endl;
  }
  ~Chassis() {
    cout << "Chassis(" << this << ") destructing..." << endl;
  }

};

class Fan {
public:
  Fan() {
    cout << "Fan(" << this << ") constructing..." << endl;
  }
  ~Fan() {
    cout << "Fan(" << this << ") destructing..." << endl;
  }
};

const int MAX_CAPACITY = 4;

class SystemBox {
private:
  Chassis cage;
  CPU *processor;
  RAM *dimms[MAX_CAPACITY];
  int number_of_ram_installed;
public:
  SystemBox(CPU *p) : processor(p) {
    cout << "SystemBox(" << this << ") constructing..." << endl;
    for (int n=0; n<MAX_CAPACITY; n++) {
      dimms[n] = NULL;
    }
    number_of_ram_installed = 0;
  }
  ~SystemBox() {
    cout << "SystemBox(" << this << ") destructing..." << endl;
  }

  bool install_ram(RAM *d) {
    if (number_of_ram_installed >= 4)
      return false;
    dimms[number_of_ram_installed++] = d;
  }
};

class Keyboard {
public:
  Keyboard() {
    cout << "Keyboard(" << this << ") constructing..." << endl;
  }
  ~Keyboard() {
    cout << "Keyboard(" << this << ") destructing..." << endl;
  }
};

class Mouse {
public:
  Mouse() {
    cout << "Mouse(" << this << ") constructing..." << endl;
  }
  ~Mouse() {
    cout << "Mouse(" << this << ") destructing..." << endl;
  }

};

class Monitor {
public:
  Monitor() {
    cout << "Monitor(" << this << ") constructing..." << endl;
  }
  ~Monitor() {
    cout << "Monitor(" << this << ") destructing..." << endl;
  }

};

class Workstation {
private:
  string hostname;
  SystemBox box;
  Mouse *mouse;
  Keyboard &kbd;
  int monitors;
  Monitor *monitor[256];
public:
  Workstation(string name, CPU *chip, Keyboard &k, Monitor *screen)
    : hostname(name), box(chip), kbd(k) {
    cout << "Workstation(" << this << ") constructing..." << endl;

    mouse = NULL;
    monitors = 1;
    monitor[0] = screen;
  }
    ~Workstation() {
      cout << "Workstation(" << this << ") destructing..." << endl;
    }
};

int main() {
  CPU inteli9;
  Keyboard keys;
  Monitor console;

  Workstation *swordfish = new Workstation("swordfish", &inteli9, keys, &console);

  delete swordfish;

  return 0;
}

