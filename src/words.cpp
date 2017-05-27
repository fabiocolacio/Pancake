#include <iostream>
#include <cstdlib>
#include "words.hpp"

using namespace std;

void add(Belt& belt) {
    if (belt.stack().length() >= 2) {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a + b);
    }
}

void subtract(Belt& belt) {
    if (belt.stack().length() >= 2) {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a - b);
    }
}

void multiply(Belt& belt) {
    if (belt.stack().length() >= 2) {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a * b);
    }
}

void divide(Belt& belt) {
    if (belt.stack().length() >= 2) {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a / b);
    }
}

void modulo(Belt& belt) {
    if (belt.stack().length() >= 2) {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a % b);
    }
}

void pop(Belt& belt) {
    if (belt.stack().length() >= 1) {
        cout << belt.stack().pop();
    }
}

void pop_int(Belt& belt) {
    if (belt.stack().length() >= 1) {
        cout << (int) belt.stack().pop();
    }
}

void multipop(Belt& belt) {
    char val = belt.stack().pop();
    while (val > 0 && belt.stack().length() > 0) {
        pop(belt);
    }
}

void multipop_int(Belt& belt) {
    char val = belt.stack().pop();
    while (val > 0 && belt.stack().length() > 0) {
        pop_int(belt);
    }
}

void drop(Belt& belt) {
    if (belt.stack().length() >= 1) {
        belt.stack().pop();
    }
}

void size(Belt& belt) {
    belt.stack().push(belt.stack().length());
}

void bye() {
    exit(0);
}

