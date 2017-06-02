#ifndef PANCAKE_Environment
#define PANCAKE_Environment

#include <istream>
#include <fstream>
#include <stack>
#include "belt.hpp"

using namespace std;

class Environment {
public:
    enum InputMode {
        INTERACTIVE, FROM_FILE
    };

private:
    ifstream file;
    stack<streampos> loop_stack;
    InputMode _mode;
    Belt stack_belt;

public:
    Environment(int, char**);
    ~Environment();
    Belt& belt();
    InputMode mode() const;
    bool eof() const;
    friend Environment& operator>>(Environment&, string&);
};

#endif
