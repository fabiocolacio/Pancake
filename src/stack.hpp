#ifndef PANCAKE_STACK_HPP
#define PANCAKE_STACK_HPP

class Stack {
private:
    struct Node {
        char val;
        Node* below;
    };
    
    Node* top;
    unsigned len;
    
public:
    Stack();
    ~Stack();
    void push(char);
    char pop();
    void swap();
    char peek() const;
    unsigned length() const;
};

#endif
