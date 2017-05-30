#ifndef PANCAKE_Environment
#define PANCAKE_Environment

#include <istream>
#include <stack>

using namespace std;

class Environment {
public:
    enum InputMode {
        INTERACTIVE, FROM_FILE
    };

private:
    stack<streampos> loop_stack;
    InputMode mode;
    istream input;

public:
    Environment(string filename = "");
    ~Environment();
    InputMode get_mode();
    stack<loop_stack> loop

};

#endif
