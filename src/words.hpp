#ifndef PANCAKE_WORDS_HPP
#define PANCAKE_WORDS_HPP

#include "belt.hpp"

void push(Belt&, char);
void add(Belt&);
void subtract(Belt&);
void multiply(Belt&);
void divide(Belt&);
void modulo(Belt&);
void pop(Belt&);
void pop_int(Belt&);
void multipop(Belt&);
void multipop_int(Belt&);
void drop(Belt&);
void size(Belt&);

#endif
