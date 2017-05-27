#include "stack.hpp"

Stack::Stack() {
    len = 0;
    top = nullptr;
}

Stack::~Stack() {
    while (top) {
        pop();
    }
}

void Stack::push(char c) {
    ++len;
    
    Node* data = new Node();
    data->val = c;
    
    if (top) {
        data->below = top;
    } else {
        data->below = nullptr;
    }
    
    top = data;
}

char Stack::pop() {
    char value = 0;

    if (top) {
        Node* ptr = top;
        value = ptr->val;
        delete ptr;
        
        top = top->below;
        
        --len;
    } else {
        value = 0;
        
        len = 0;
    }
    
    return value;
}

void Stack::swap() {
    if (len >= 2) {
        char a = pop();
        char b = pop();
        
        push(a);
        push(b);
    }
}

char Stack::peek() const {
    if (top) {
        return top->val;
    }
    
    return 0;
}

unsigned Stack::length() const {
    return len;
}

