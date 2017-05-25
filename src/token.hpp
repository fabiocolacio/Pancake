#ifndef PANCAKE_TOKEN_HPP
#define PANCAKE_TOKEN_HPP

#include <string>

using namespace std;

enum InputMode {
    INTERACTIVE, FROM_FILE
};

void parse_token(string);

#endif
