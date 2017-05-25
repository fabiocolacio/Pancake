#include <string>
#include <iostream>
#include "token.hpp"
#include "belt.hpp"

using namespace std;

void parse_token(string token, Belt& belt) {
    int tmp;
    try {
        tmp = stoi(token);
        belt.stack().push((char)tmp);
    } catch (...) {}

    if (token == "peek") {
        cout << belt.stack().peek() << endl;
    } else if (token == "peek_int") {
        cout << (int) belt.stack().peek() << endl;
    } else if (token == "+") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a + b);
    }

    cout << "parsed token: " << token << endl;
}

