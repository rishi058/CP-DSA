#include <iostream>
#include <cmath>
#include <algorithm> // For std::min

long long solve(long long x1, long long x2, long long y2, long long x3, long long y3, long long k) {
    // Calculate values for the two cases
    long long numerator1 = 2 * k - x1 * (y2 - y3) + x3 * y2 - x2 * y3;
    long long numerator2 = -2 * k - x1 * (y2 - y3) + x3 * y2 - x2 * y3;
    long long denominator = x2 + x3;

    // Use long long to ensure large number handling and avoid division by zero.
    // Also, handle case where denominator could be zero.
    if (denominator == 0) {
        // If x2 + x3 == 0, we need to check if both cases are possible or if it's an edge case.
        // In practice, this may imply special handling or a different approach based on the problem constraints.
        // For now, returning a large number or an error code might be a reasonable placeholder.
        throw std::runtime_error("Denominator is zero, special handling required.");
    }

    // Calculate the minimum value of y1 based on the two cases
    long long y1_min_case1 = (numerator1 + denominator - 1) / denominator; // Ceiling division
    long long y1_min_case2 = (numerator2 + denominator - 1) / denominator; // Ceiling division

    // Return the minimum value of y1 from the two cases
    return std::min(y1_min_case1, y1_min_case2);
}

int main() {
    // Example usage
    long long x1 = 1, x2 = 2, y2 = 2, x3 = 3, y3 = 3, k = 10;
    try {
        std::cout << "Minimum y1: " << solve(x1, x2, y2, x3, y3, k) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
