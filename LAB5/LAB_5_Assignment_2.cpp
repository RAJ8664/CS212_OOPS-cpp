/*Author : RAJ ROY*/
/*Scholar id : 2212002*/
#include <iostream>


template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Before swapping:" << std::endl;
    std::cout << "num1: " << x << ", num2: " << y << std::endl;

    // Swapping integers
    swap(x, y);
    std::cout << "After swapping:" << std::endl;
    std::cout << "num1: " << x << ", num2: " << y << std::endl;

    double double1 = 3.14, double2 = 6.28;
    std::cout << "Before swapping:" << std::endl;
    std::cout << "double1: " << double1 << ", double2: " << double2 << std::endl;

    // Swapping doubles
    swap(double1, double2);
    std::cout << "After swapping:" << std::endl;
    std::cout << "double1: " << double1 << ", double2: " << double2 << std::endl;

    return 0;
}