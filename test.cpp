#include <iostream>
using namespace std;

const int value = 22;

int main() {
    const int * const ptr = &value;

    cout << *ptr;
}