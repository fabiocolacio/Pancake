#include <iostream>
#include <sstream>
#include "token.hpp"
#include "words.hpp"

using namespace std;

void parse_line(string line, Environment& env) {
    Belt& belt = env.belt();
    string token = "", tmp = "";
    stringstream token_reader = stringstream(line);
    while (!token_reader.eof()) {
        token_reader >> token;

        if (token.at(0) == '"') {
            tmp = token;
        } else if (token.at(token.length() - 1) == '"' &&
                   tmp.at(0) == '"') {
            tmp += " " + token;
            parse_token(tmp, env);
            tmp = "";
        } else if (tmp != "") {
            tmp += " " + token;
        } else if (token == "#") {
            break;
        } else {
            parse_token(token, env);
        }
    }
}

void parse_token(string token, Environment& env) {
    if (token.at(0) == '{') {
        string func_name = token.substr(1);
        env.block().push(func_name);
        env.define_function(func_name);
    } else if (token == "[") {
        env.block().push("loop");
        env.loops().push("");
    }

    if (env.block().empty()) {
        Belt& belt = env.belt();
        int tmp;
        try {
            tmp = stoi(token);
            belt.stack().push((char)tmp);
        } catch (...) {}

        if (token == "peek") {
            peek(belt);
        } else if (token == "peek_int") {
            peek_int(belt);
        } else if (token == "+") {
            add(belt);
        } else if (token =="-") {
            subtract(belt);
        } else if (token =="*") {
            multiply(belt);
        } else if (token =="/") {
            divide(belt);
        } else if (token =="%") {
            modulo(belt);
        } else if (token == "'\\n'") {
            belt.stack().push('\n');
        } else if (token.at(0) == '\'' &&
                   token.at(1) == '\\' &&
                   token.at(2) == '\'' &&
                   token.at(2) == '\'' &&
                   token.length() == 4) {
            belt.stack().push('\'');
        } else if (token.at(0) == '\'' &&
                   token.at(2) == '\'') {
            belt.stack().push(token.at(1));
        } else if (token.at(0) == '"' &&
                   token.at(token.length() - 1) == '"') {
            for (int i = token.length() - 2; i > 0; --i) {
                belt.stack().push(token.at(i));
            }
        } else if (token == "drop") {
            drop(belt);
        } else if (token == "pop") {
            pop(belt);
        } else if (token == "pop_int") {
            pop_int(belt);
        } else if (token == "multipop") {
            multipop(belt);
        } else if (token == "multipop_int") {
            multipop_int(belt);
        } else if (token == "size") {
            size(belt);
        } else if (token == "bye") {
            bye();
        } else if (token == "pop_all") {
            pop_all(belt);
        } else if (token == "pop_all_int") {
            pop_all_int(belt);
        } else if (token == "drop_all") {
            drop_all(belt);
        } else {
            env.execute_function(token);
        }
    } else {
        if (token == "}") {
            env.block().pop();
        } else if (token == "]") {
            env.block().pop();
            stringstream loop(env.loops().top());
            streampos loop_start = loop.tellg();
            string line;
            env.loops().pop();

            while (env.belt().stack().peek()) {
                while (!loop.eof()) {
                    try {
                        getline(loop, line);
                        parse_line(line, env);
                    } catch (out_of_range e) {}
                }
                loop.seekg(loop_start);
            }
        } else if (token.at(0) != '{' && token != "[") {
            if (env.block().top() == "loop") {
                env.loops().top() += " " + token;
            } else {
                env.append_function(env.block().top(), " " + token);
            }
        }
    }
}

