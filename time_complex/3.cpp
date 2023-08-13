#include <compare>
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // Compare a and b using the three-way comparison operator
    if ((a <=> b) == 0) {
        std::cout << "a and b are equal" << std::endl;
    } else {
        std::cout << "a and b are not equal" << std::endl;
    }
    std::strong_ordering c = (a <=> b);
    std::cout<<c<<std::endl;
    return 0;
}
