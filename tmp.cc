#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> a;
    a = 3;
    std::cout << 3 << std::endl;
}