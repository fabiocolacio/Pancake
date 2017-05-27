#include <string>
#include <iostream>
#include "token.hpp"
#include "belt.hpp"
#include "words.hpp"

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
        add(belt);
    } else if (token =="-") {
        subtract(belt);
    } else if (token =="*") {
        multiply(belt);
    } else if (token =="/") {
        divide(belt);
    } else if (token =="%") {
        modulo(belt);
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
        drop(belt);
    } else if (token == "pop") {
        pop(belt);
    } else if (token == "pop_int") {
        pop_int(belt);
    } else if (token == "multipop") {
        multipop(belt);
    } else if (token == "multipop_int") {
        multipop_int(belt);
    } else if (token == "size") {
        size(belt);
    } else if (token == "bye") {
        bye();
    }
}

