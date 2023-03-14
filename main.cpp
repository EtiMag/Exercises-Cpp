#include <algorithm>
#include <ios>
#include <iostream>
#include <type_traits>
#include "main.h"
#include <regex>

using namespace std;

int main() {
    // input & output
    sayHello(3);
    testIncrements();
    testRegex();
    return 0;
}

void testIncrements() {
    // test increments on references and pointers
    cout << "--- function testIncrements ---" << endl;
    int i = 0;
    Inc(i);
    cout << i << endl;
    Inc(&i);
    cout << i << endl;
}

void Inc(int& i) {
    i++;
}

void Inc(int* iptr) {
    cout << "ptr" << endl;
    (*iptr)++;
}

void sayHello(int n) {
    cout << "--- function sayHello ---" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Hello" << i << endl;
    }
}

void testRegex() {
    // regex_match
    cout << "--- function testRegex ---" << endl;
    string testString = "This is a test string ! 12f34";
    regex pattern {R"((.*)(\d|f{3,10}))"};
    bool IsMatching = regex_match(testString, pattern);
    cout << boolalpha;
    cout << IsMatching << endl;

    // regex_search (put the first match in match)
    smatch match;
    pattern = R"(.{2})";
    regex_search(testString.cbegin(), testString.cend(), match, pattern);
    cout << match.str() << endl;

    // regex_iterator
    sregex_iterator matchesBegin(testString.cbegin(), testString.cend(), pattern), matchesEnd;
    for_each(matchesBegin, matchesEnd, displayMatch);
    for_each(matchesBegin, matchesEnd, [](const auto& subMatchIter) { // same loop
        cout << subMatchIter.str() << endl;
    });
    for (sregex_iterator it = matchesBegin; it != matchesEnd; ++it) { // same loop
        cout << it->str() << endl;
    }
}

void displayMatch(const smatch& it) {
    cout << it.str() << endl;
}