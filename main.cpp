#include <ios>
#include <iostream>
#include <type_traits>
#include "main.h"
#include <regex>

using namespace std;

int main() {
    // input & output
    sayHello(8);

    // references
    int i = 0;
    Inc(i);
    cout << i << endl;
    Inc(&i);
    cout << i << endl;

    cout << test_const_var << endl;

    const string& str1 = "123abc";
    const string& str2 = "123";
    cout << boolalpha;
    cout << static_cast<int>(str1 != str2) << endl;
    cout << true << endl;

    // regex
    string testString("This is a test string ! 12f45");
    regex pat {R"((.*)(\d|f{5}))"};
    bool IsMatching = regex_match(testString, pat);
    cout << IsMatching << endl;

    smatch matches;
    pat = R"(s)";
    regex_search(testString.cbegin(), testString.cend(), matches, pat);

    
    return 0;
}

void Inc(int& i) {
    i++;
}

void Inc(int* iptr) {
    cout << "ptr" << endl;
    (*iptr)++;
}

void sayHello(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Hello" << i << endl;
    }
}
