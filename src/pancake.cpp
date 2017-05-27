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
    
    stringstream token_reader;
    string token;
    
    switch (mode) {
        case FROM_FILE:
            {
                char* filename = argv[argc - 1];
                ifstream file(filename);
                
                while (!file.eof()) {
                    file >> token;
                    if (!file.eof()) {
                        parse_token(token, stack_belt);
                    }
                }
            }
            break;
            
        case INTERACTIVE:
            {
                while (true) {
                    cout << "%> ";
                    try {
                        getline(cin, token);
                        token_reader = stringstream(token);
                        while (!token_reader.eof()) {
                            token_reader >> token;
                            parse_token(token, stack_belt);
                        }
                    } catch (...) {}
                }
            }
            break;
    }
    
    return 0;
}
