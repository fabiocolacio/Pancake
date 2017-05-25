#ifndef PANCAKE_BELT_HPP
#define PANCAKE_BELT_HPP

#include "stack.hpp"

class Belt {
private:
    struct Node {
        Node* next;
        Node* prev;
        Stack stack;
    };
    
    Node* current;
    
public:
    Belt();
    ~Belt();
    void cycle_next();
    void cycle_prev();
    Stack get();
    Stack get_next();
    Stack get_prev();
};

#endif
