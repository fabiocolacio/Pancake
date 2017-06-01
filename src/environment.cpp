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

istream& Environment::stream() {
    switch (mode) {
        case FROM_FILE:
            return file;
            break;

        case INTERACTIVE:
            return cin;
            break;
    }
}

Environment::InputMode Environment::get_mode() {
    return _mode;
}

bool Environment::eof() {
    switch (mode) {
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

istream& operator>>(Environment& env, string& str) {
    try {
        switch (mode) {
            case FROM_FILE:
                getline(file, str);
                break;

            case INTERACTIVE:
                cout << "%> ";
                getline(cin, str);
                break;
        }
    } catch (...) {}

    return env;
}

