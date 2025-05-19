#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

// O(n) recursive power function
// What: Calculates x^n using linear recursion
// How: Multiplies x by itself n times recursively
// Why: Simple implementation but less efficient for large n
double powerLinear(double x, int n) {
    // Base cases
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n < 0) return 1.0 / powerLinear(x, -n);
    
    // Recursive case: x^n = x * x^(n-1)
    return x * powerLinear(x, n - 1);
}

// O(log n) recursive power function
// What: Calculates x^n using binary recursion
// How: Splits the problem into even/odd cases and uses the square property
// Why: More efficient for large n by reducing the number of multiplications
double powerLog(double x, int n) {
    // Base cases
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n < 0) return 1.0 / powerLog(x, -n);
    
    // Recursive case with even/odd split
    if (n % 2 == 0) {
        // For even n: x^n = (x^2)^(n/2)
        double temp = powerLog(x, n/2);
        return temp * temp;
    } else {
        // For odd n: x^n = x * (x^2)^((n-1)/2)
        return x * powerLog(x * x, (n-1)/2);
    }
}

// Function to test both power functions
void testPowerFunctions() {
    // Test cases with different values of x and n
    struct TestCase {
        double x;
        int n;
    };
    
    TestCase tests[] = {
        {2.0, 0},    // x^0
        {2.0, 1},    // x^1
        {2.0, 2},    // x^2
        {2.0, 3},    // x^3
        {2.0, 4},    // x^4
        {2.0, 5},    // x^5
        {2.0, -1},   // x^-1
        {2.0, -2},   // x^-2
        {3.0, 3},    // Different base
        {1.5, 4}     // Decimal base
    };
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Testing Power Functions\n";
    std::cout << "======================\n";
    std::cout << "x\tn\tO(n)\t\tO(log n)\tstd::pow\n";
    std::cout << "------------------------------------------------\n";
    
    for (const auto& test : tests) {
        double resultLinear = powerLinear(test.x, test.n);
        double resultLog = powerLog(test.x, test.n);
        double resultStd = std::pow(test.x, test.n);
        
        std::cout << test.x << "\t" << test.n << "\t"
                  << resultLinear << "\t"
                  << resultLog << "\t"
                  << resultStd << "\n";
    }
}

// Function to compare performance
void comparePerformance() {
    const int n = 1000000;  // Large exponent for performance testing
    const double x = 2.0;
    
    std::cout << "\nPerformance Comparison (n = " << n << "):\n";
    std::cout << "================================\n";
    
    // Test O(n) version
    auto start = std::chrono::high_resolution_clock::now();
    double resultLinear = powerLinear(x, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationLinear = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Test O(log n) version
    start = std::chrono::high_resolution_clock::now();
    double resultLog = powerLog(x, n);
    end = std::chrono::high_resolution_clock::now();
    auto durationLog = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "O(n) time:     " << durationLinear.count() << " microseconds\n";
    std::cout << "O(log n) time: " << durationLog.count() << " microseconds\n";
    std::cout << "Speedup ratio: " << static_cast<double>(durationLinear.count()) / durationLog.count() << "x\n";
}

int main() {
    // Test both functions with various inputs
    testPowerFunctions();
    
    // Compare performance with large exponent
    comparePerformance();
    
    return 0;
}
