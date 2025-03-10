#include <iostream>
using namespace std;

void swap(int*& x, int*& y) {

    int* temp = x;
    x = y;
    y = x;

}

int main () {

    int a = 10;
    int b = 20;
    swap(a, b);
    cout << a << endl;
    cout << b;

    return 0;

}