#include "belt.hpp"

Belt::Belt() {
    len = 1;
    current = new Node();
    
    current->stack = Stack();
    
    current->left = current;
    current->right = current;
}

Belt::~Belt() {
    while (len > 1) {
        destroy_mov_left();
    }
    delete current;
}

void Belt::expand_left() {
    ++len;
    
    Node* node = new Node();
    
    node->stack = Stack();
    
    node->left = current->left;
    node->right = current;
    
    current->left = node;
}

void Belt::expand_right() {
    ++len;
    
    Node* node = new Node();
    
    node->stack = Stack();
    
    node->right = current->right;
    node->left = current;
    
    current->right = node;
}

void Belt::cycle_left() {
    current = current->left;
}

void Belt::cycle_right() {
    current = current->right;
}

void Belt::destroy_mov_right() {
    if (len > 0) {
        --len;
    
        current->right->left = current->left;
        current->left->right = current->right;
        
        Node* tmp = current;
        
        current = current->right;
        
        delete tmp;
    }
}

void Belt::destroy_mov_left() {
    if (len > 0) {
        --len;
    
        current->right->left = current->left;
        current->left->right = current->right;
        
        Node* tmp = current;
        
        current = current->left;
        
        delete tmp;
    }
}

void Belt::destroy_left() {
    if (len > 0) {
        cycle_left();
        destroy_mov_right();
    }
}

void Belt::destroy_right() {
    if (len > 0) {
        cycle_right();
        destroy_mov_left();
    }
}

Stack& Belt::stack() const {
    Stack& ref = current->stack;
    return ref;
}

Stack& Belt::get_left() const {
    Stack& ref = current->left->stack;
    return ref;
}

Stack& Belt::get_right() const {
    Stack& ref = current->right->stack;
    return ref;
}

