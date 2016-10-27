#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void print() {
    cout << "\n";
}

// print a message to the user
void print(string message) {
    cout << message << "\n";
}

// read text from the command line
string read() {
    string temp;
    cin >> temp;
    return temp;
}

// split a string by a delimiter into a given array
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

// split an string by a delimiter and return an array of individual delimited elements
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}