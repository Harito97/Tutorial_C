#include <iostream>
#include <vector>

int main() {
    // Low-level programming
    int number = 42;
    int* ptr_number = &number;
    std::cout << *ptr_number << std::endl;
    
    // High-level programming
    std::vector<int> myVector = {1, 2, 3};
    for(const auto &i: myVector) {
        std::cout << i << std::endl;
    }
}
