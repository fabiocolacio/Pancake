#include <iostream>
#include <fstream>
#include <cstdlib>
#include "belt.hpp"
#include "token.hpp"

using namespace std;

int main (int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: "
             << argv[0]
             << " <filename>"
             << endl;
        return 0;
    }
    
    char* filename = argv[argc - 1];
    ifstream file(filename);
    
    Belt stack_belt;
    
    string token;
    
    while (!file.eof()) {
        file >> token;
        if (!file.eof()) {
            parse_token(token, stack_belt);
        }
    }
    
    return 0;
}
