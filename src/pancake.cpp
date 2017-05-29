#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "belt.hpp"
#include "token.hpp"

using namespace std;

int main (int argc, char** argv) {
    InputMode mode;

    if (argc < 2) {
        mode = INTERACTIVE;
    } else {
        mode = FROM_FILE;
    }
    
    Belt stack_belt;
    
    string line;
    
    switch (mode) {
        case FROM_FILE:
            {
                char* filename = argv[argc - 1];
                ifstream file(filename);
                
                while (!file.eof()) {
                    try {
                        getline(file, line);
                        parse_line(line, stack_belt);
                    } catch (...) {}
                }
            }
            break;
            
        case INTERACTIVE:
            {
                while (true) {
                    cout << "%> ";
                    try {
                        getline(cin, line);
                        parse_line(line, stack_belt);
                    } catch (...) {}
                }
            }
            break;
    }
    
    return 0;
}
