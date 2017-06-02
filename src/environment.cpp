#include <iostream>
#include "environment.hpp"

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
    try {
        switch (env._mode) {
            case Environment::FROM_FILE:
                getline(env.file, str);
                break;

            case Environment::INTERACTIVE:
                cout << "%> ";
                getline(cin, str);
                break;
        }
    } catch (...) {}
    return env;
}

