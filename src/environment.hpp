#ifndef PANCAKE_Environment
#define PANCAKE_Environment

#include <istream>
#include <fstream>
#include <map>
#include "belt.hpp"

using namespace std;

class Environment {
public:
    enum InputMode {
        INTERACTIVE, FROM_FILE
    };

private:
    map<string, string> functions;
    ifstream file;
    InputMode _mode;
    Belt stack_belt;

public:
    Environment(int, char**);
    ~Environment();
    Belt& belt();

    void execute_function(string);
    void define_function(string, string);
    void append_function(string, string);
    size_t delete_function(string);

    InputMode mode() const;
    bool eof() const;
    friend Environment& operator>>(Environment&, string&);
};

#endif
