#include <iostream>

union A {
    int a;
    int *ptr;
};


int main() {
    A un;
    int val = 3;
    int *p = new int(4);
    un.a = 3;
    un.ptr = p;
    std::cout << *un.ptr << std::endl;
    delete p;
}