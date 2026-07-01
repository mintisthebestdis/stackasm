#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    vector<string> lexer;
    vector<int> stack;

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

    int tmp;

    for (int i = 0; i < lexer.size(); i++) {

        if (lexer[i] == "POP") {
            stack.pop_back();
        } else if (lexer[i] == "PUSH") {
            stack.push_back(stoi(lexer[i + 1]));
            i++; 
        } else if (lexer[i] == "DUP") {
            stack.push_back(stack.back());
        } else if (lexer[i] == "SWAP") {
            int size = stack.size();
            tmp = stack[size - 1];
            stack[size - 1] = stack[size - 2];
            stack[size - 2] = tmp;   
        } else if (lexer[i] == "ADD") {
            int size = stack.size();
            tmp = stack[size - 2] + stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
        } else if (lexer[i] == "SUB") {
            int size = stack.size();
            tmp = stack[size - 2] - stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(tmp);   
        } else if (lexer[i] == "EMIT") {
            cout << static_cast<char>(stack.back());  
        } else if (lexer[i] == "OUTPUT") {
            cout << stack.back();
        }
    }

    return 0;
}
