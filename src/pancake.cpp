#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "environment.hpp"
#include "belt.hpp"
#include "token.hpp"

using namespace std;

int main (int argc, char** argv) {
    Environment env(argc, argv);
    string line;

    while (!env.eof()) {
        env >> line;
        parse_line(line);
    }

    return 0;
}
