#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

void print_stacks(int* Cstack, std::vector<int>& CPPstack, int size) {
    // back to front stack print
    cout << "CPPSTACK: " << endl;
    for (auto iter = CPPstack.rbegin(); iter != CPPstack.rend(); ++iter) {
        cout << *iter << endl;
    }
    cout << "CSTACK: " << endl;
    for (int i = size - 1; i >= 0; --i) {
        if(Cstack[i] != 0) {
            cout << Cstack[i] << endl;
        }
    }
}

void extract_instructions(string instruction_line, string* instruction_command, int* instruction_int) {
    // hopefully it's cool to use .find(), I could loop through it if you want
    auto space_index = instruction_line.find(' ');

    // check for end position, had to look this up
    if (space_index != string::npos) {
        *instruction_command = instruction_line.substr(0, space_index);
        *instruction_int = std::stoi(instruction_line.substr(space_index + 1));
    } else {
        // instruction broke, just stop.
        cout << "Failed to read instruction line: \n" << instruction_line << endl;
        exit(-1);
    }
}

void push(int* cstack, int size, int* stack_count, int input_value) {
    if( *stack_count+1 > size) {
        cout << "NO PUSH - STACK IS FULL" << endl;
    }
    cstack[*stack_count] = input_value;
    *stack_count += 1;
}

void pop(int* cstack, int* stack_count) {
    cstack[*stack_count-1] = 0;
    *stack_count -= 1;
}

void top(int* cstack, int stack_count) {
    if (stack_count == 0) {
        cout << "NO TOP" << endl;
    } else {
        cout << cstack[stack_count-1] << endl;
    }
}

void processData(ifstream &inf, int* cstack, vector<int> &cppstack, int size) {
    int numlets = 0;
    string instruction_line;

    // loop the file
    bool isFirstLine = true;
    while (getline (inf, instruction_line)) {
        // skip size line
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        // split instruction string into instruction and input int
        string instruction;
        int input_integer;
        extract_instructions(instruction_line, &instruction, &input_integer);

        if (instruction == "PUSH") {
            cppstack.push_back(input_integer);
            push(cstack, size, &numlets, input_integer);
        }
        else if (instruction == "POP") {
            if(cppstack.empty()) {
                cout << "NO POP - STACK IS EMPTY" << endl;
            } else {
                cppstack.pop_back();
            }
            pop(cstack, &numlets);
        }
        else if (instruction == "TOP") {
            if(cppstack.empty()) {
                cout << "NO TOP" << endl;
            } else {
                cout << cppstack.back() << endl;
            }
            top(cstack, numlets);
        }
    }
}

int main() {
    // read in file
    string input_filepath;
    cout << "Filepath: ";
    cin >> input_filepath;
    ifstream inf(input_filepath);

    if(!inf) {
        cerr << "Error opening file " << input_filepath << endl;
        exit(-1);
    }

    // Read in size
    int size;
    inf >> size;

    // so now we have the instructions isolated from the array size config and we can run them
    int* Cstack = (int *) malloc( size * sizeof(int) );
    vector<int> CPPstack;
    processData(inf, Cstack, CPPstack, size);
    print_stacks(Cstack, CPPstack, size);

    inf.close();
    return 0;
}

