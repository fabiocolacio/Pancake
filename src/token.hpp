#ifndef PANCAKE_TOKEN_HPP
#define PANCAKE_TOKEN_HPP

#include <string>
#include "belt.hpp"

using namespace std;

enum InputMode {
    INTERACTIVE, FROM_FILE
};

void parse_token(string, Belt&);
    
#endif
