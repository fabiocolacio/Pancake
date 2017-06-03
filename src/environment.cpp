#include <iostream>
#include <sstream>
#include "environment.hpp"
#include "token.hpp"

using namespace std;

Environment::Environment(int argc, char** argv) {
    if (argc < 2) {
        _mode = INTERACTIVE;
    } else {
        char* filename = argv[argc - 1];
        file = ifstream(filename);
        _mode = FROM_FILE;
    }
}

Environment::~Environment() {

}

Belt& Environment::belt () {
    return stack_belt;
}

Environment::InputMode Environment::mode() const {
    return _mode;
}

void Environment::execute_function(string func_name) {
    cout << "executing function: " << func_name << endl;
    stringstream func(functions[func_name]);
    string line;

    while (!func.eof()) {
        try {
            getline(func, line);
            parse_line(line, *this);
        } catch (out_of_range e) {}
    }
}

void Environment::define_function(string func_name, string content) {
    cout << "defining func: " << func_name << endl;
    functions[func_name] = content;
}

void Environment::append_function(string func_name, string content) {
    cout << "appending \n" << content << " to " << func_name << endl;
    functions[func_name] += "\n" + content;
}

size_t Environment::delete_function(string func_name) {
    return functions.erase(func_name);
}

stack<string>& Environment::block() {
    return _block;
}

bool Environment::eof() const {
    switch (_mode) {
        case FROM_FILE:
            return file.eof();
            break;

        case INTERACTIVE:
            return false;
            break;

        default:
            return false;
            break;
    }
}

Environment& operator>>(Environment& env, string& str) {
    switch (env._mode) {
        case Environment::FROM_FILE:
            getline(env.file, str);
            break;

        case Environment::INTERACTIVE:
            cout << "%> ";
            getline(cin, str);
            break;
    }
    return env;
}

