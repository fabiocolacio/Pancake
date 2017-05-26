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
        cout << belt.stack().peek();
    } else if (token == "peek_int") {
        cout << (int) belt.stack().peek();
    } else if (token == "+") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a + b);
    } else if (token =="-") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a - b);
    } else if (token =="*") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a * b);
    } else if (token =="/") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a / b);
    } else if (token =="%") {
        char b = belt.stack().pop();
        char a = belt.stack().pop();
        belt.stack().push(a % b);
    } else if (token == "'\\n'") {
        belt.stack().push('\n');
    } else if (token.at(0) == '\'' &&
               token.at(1) == '\\' &&
               token.at(2) == '\'' &&
               token.at(2) == '\'' &&
               token.length() == 4) {
        belt.stack().push('\'');
    } else if (token.at(0) == '\'' &&
               token.at(2) == '\'') {
        belt.stack().push(token.at(1));
    } else if (token.at(0) == '"' &&
               token.at(token.length() - 1) == '"') {
        for (int i = token.length() - 2; i > 0; --i) {
            belt.stack().push(token.at(i));
        }
    } else if (token == "drop") {
        belt.stack().pop();
    } else if (token == "pop") {
        cout << belt.stack().pop();
    } else if (token == "pop_int") {
        cout << (int)belt.stack().pop();
    }
}

