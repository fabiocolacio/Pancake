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
    unsigned len;
    
public:
    Belt();
    ~Belt();
    void cycle_next();
    void cycle_prev();
    Stack& get() const;
    Stack& get_next() const;
    Stack& get_prev() const;
};

#endif
