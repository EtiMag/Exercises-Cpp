#include <algorithm>
#include <ios>
#include <iostream>
#include <type_traits>
#include "main.h"
#include <regex>


int main() {
    // input & output
    sayHello(3);
    testIncrements();
    testRegex();
    int x1 = 1;
    float x2 = 0.3;
    displayNumber(x1);
    displayNumber(x2);
    char buffer[] = "B123456789";
    std::cout << myAtoi<5>(buffer + 1) << std::endl;
    return 0;
}

void testIncrements() {
    // test increments on references and pointers
    std::cout << "--- function testIncrements ---" << std::endl;
    int i = 0;
    Inc(i);
    std::cout << i << std::endl;
    Inc(&i);
    std::cout << i << std::endl;
}

void Inc(int& i) {
    i++;
}

void Inc(int* iptr) {
    std::cout << "ptr" << std::endl;
    (*iptr)++;
}

void sayHello(int n) {
    std::cout << "--- function sayHello ---" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Hello" << i << std::endl;
    }
}

void testRegex() {
    // regex_match
    std::cout << "--- function testRegex ---" << std::endl;
    std::string testString = "This is a test string ! 12f34";
    std::regex pattern {R"((.*)(\d|f{3,10}))"};
    bool IsMatching = regex_match(testString, pattern);
    std::cout << std::boolalpha;
    std::cout << IsMatching << std::endl;

    // regex_search (put the first match in match)
    std::smatch match;
    pattern = R"(.{2})";
    regex_search(testString.cbegin(), testString.cend(), match, pattern);
    std::cout << match.str() << std::endl;

    // regex_iterator
    std::sregex_iterator matchesBegin(testString.cbegin(), testString.cend(), pattern), matchesEnd;
    for_each(matchesBegin, matchesEnd, displayMatch);
    for_each(matchesBegin, matchesEnd, [](const auto& subMatchIter) { // same loop
        std::cout << subMatchIter.str() << std::endl;
    });
    for (std::sregex_iterator it = matchesBegin; it != matchesEnd; ++it) { // same loop
        std::cout << it->str() << std::endl;
    }
}

void displayMatch(const std::smatch& it) {
    std::cout << it.str() << std::endl;
}

template<typename T>
void displayNumber(const T& x) {
    std::cout << "--- function displayNumber ---" << std::endl;
    std::cout << x << std::endl;
}

template<int N>
int myAtoi(char* sPtr) {
    std::cout << "--- function myAtoi ---" << std::endl;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        result *= 10;
        result += *(sPtr + i) - '0';
    }
    return result;
}
