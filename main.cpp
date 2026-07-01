#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

void segfault() {
    int* ptr = nullptr; 
    *ptr = 42;
}

using namespace std;

int main(int argc, char *argv[]) {
     
    cout << unitbuf;
    vector<string> lexer;
    vector<int> stack;
    map<string, int> labels;

    if (argv[1] == NULL) {
        cout << "select a file please." << endl;
        return 1;
    }

    ifstream readfile(argv[1]);
    if (!readfile.is_open()) {
        cout << "file does not exist or the file descriptor failed to open." << endl;
        return 1;
    } 

    string currentread;
    while (readfile >> currentread) {
        lexer.push_back(currentread);
    }

   
    for (int i = 0; i < lexer.size(); i++) {
        char first_char = lexer[i][0];
        if (first_char >= 'a' && first_char <= 'z') {
            labels.insert({lexer[i], i});
        }
    }

    int tmp;
    int i = 0;

    
    while (i < lexer.size()) {

        if (lexer[i] == "JMP") {
            auto address = labels.find(lexer[i + 1]);
            if (address != labels.end()) {
                i = address->second;
            } else {
                segfault();
            }
        } 
        else if (lexer[i] == "JZ") {
            auto address = labels.find(lexer[i + 1]);
            if (address != labels.end()) {
                if (stack.back() == 0) {
                    i = address->second;
                } else {
                    i += 2; 
                }
                stack.pop_back();
            } else {
                segfault();
            }
        } 
        else if (lexer[i] == "POP") {
            stack.pop_back();
            i++;
        } 
        else if (lexer[i] == "PUSH") {
            stack.push_back(stoi(lexer[i + 1]));
            i += 2;
        } 
        else if (lexer[i] == "DUP") {
            stack.push_back(stack.back());
            i++;
        } 
        else if (lexer[i] == "SWAP") {
            int size = stack.size();
            tmp = stack[size - 1];
            stack[size - 1] = stack[size - 2];
            stack[size - 2] = tmp;   
            i++;
        } 
        else if (lexer[i] == "ADD") {
            int size = stack.size();
            tmp = stack[size - 2] + stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
            i++;
        } 
        else if (lexer[i] == "SUB") {
            int size = stack.size();
            tmp = stack[size - 2] - stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
            i++;
        } 
        else if (lexer[i] == "EMIT") {
            cout << static_cast<char>(stack.back());  
            i++;
        } 
        else if (lexer[i] == "OUTPUT") {
            cout << stack.back();
            i++;
        }else if (lexer[i] == "MUL") {
            int size = stack.size();
            tmp = stack[size - 2] * stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
            i++;
        } 
        else if (lexer[i] == "DIV") {
            int size = stack.size();
            if (stack[size - 1] == 0) {
                segfault(); 
            }
            tmp = stack[size - 2] / stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
            i++;
        } else if (lexer[i] == "READ") {
          cin >> tmp;
          stack.push_back(tmp);
          i++;
        } else {
            i++; 
        }
    }

    return 0;
}
