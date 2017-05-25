#ifndef PANCAKE_BELT_HPP
#define PANCAKE_BELT_HPP

#include "stack.hpp"

class Belt {
private:
    struct Node {
        Node* left;
        Node* right;
        Stack stack;
    };
    
    Node* current;
    unsigned len;
    
public:
    Belt();
    ~Belt();
    
    void expand_left();
    void expand_right();
    
    void cycle_left();
    void cycle_right();
    
    void destroy_mov_right();
    void destroy_mov_left();
    void destroy_left();
    void destroy_right();
    
    Stack& stack() const;
    Stack& get_left() const;
    Stack& get_right() const;
};

#endif
