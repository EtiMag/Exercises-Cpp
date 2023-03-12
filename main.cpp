#include <iostream>

using namespace std;

void sayHello(int);
void Inc(int&);
void Inc(int*);



int main() {
    // input & output
    sayHello(8);

    // references
    int i = 0;
    Inc(i);
    cout << i << endl;
    Inc(&i);
    cout << i << endl;
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

