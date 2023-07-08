#include <iostream>
#include <iomanip>  // Added for std::fixed

int main() {
    double height = 143263;
    double base = 86588;

    double area = 0.5 * base * height;

    std::cout << "The area of the isosceles triangle is: " << std::fixed << std::setprecision(0) << area << std::endl;

    return 0;
}
