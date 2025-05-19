#include <iostream>
#include <iomanip>
#include <cmath>

// Forward declaration of S(x) since it's used in C(x)
double calculateS(double x, double epsilon);

// Function to calculate C(x) recursively
// What: Calculates C(x) using the given recursive formula
// How: Uses base case for small x and recursive formula for larger x
// Why: Implements the mathematical function C(2x) = C(x)S(x)/2
double calculateC(double x, double epsilon) {
    // Base case: when |x| < epsilon
    if (std::abs(x) < epsilon) {
        return 1.0/x + x/6.0;
    }
    
    // Recursive case: C(2x) = C(x)S(x)/2
    // We need to work backwards from 2x to x
    double cx = calculateC(x/2.0, epsilon);
    double sx = calculateS(x/2.0, epsilon);
    return (cx * sx) / 2.0;
}

// Function to calculate S(x) recursively
// What: Calculates S(x) using the given recursive formula
// How: Uses base case for small x and recursive formula for larger x
// Why: Implements the mathematical function S(2x) = C²(x)S²(x)/(C²(x)-S²(x))
double calculateS(double x, double epsilon) {
    // Base case: when |x| < epsilon
    if (std::abs(x) < epsilon) {
        return 1.0 + (x * x) / 2.0;
    }
    
    // Recursive case: S(2x) = C²(x)S²(x)/(C²(x)-S²(x))
    // We need to work backwards from 2x to x
    double cx = calculateC(x/2.0, epsilon);
    double sx = calculateS(x/2.0, epsilon);
    double cx2 = cx * cx;
    double sx2 = sx * sx;
    return (cx2 * sx2) / (cx2 - sx2);
}

// Function to test both functions
void testFunctions() {
    const double epsilon = 1e-6;
    const double step = 0.1;
    const double maxX = std::atan(1.0);  // arctan(1) = π/4
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Testing C(x) and S(x) functions\n";
    std::cout << "=============================\n";
    std::cout << "x\t\tC(x)\t\tS(x)\t\tC(2x)\t\tS(2x)\n";
    std::cout << "--------------------------------------------------------\n";
    
    // Test values from -arctan(1) to arctan(1) with step 0.1
    for (double x = -maxX; x <= maxX; x += step) {
        double cx = calculateC(x, epsilon);
        double sx = calculateS(x, epsilon);
        double c2x = calculateC(2*x, epsilon);
        double s2x = calculateS(2*x, epsilon);
        
        std::cout << x << "\t\t" 
                  << cx << "\t\t" 
                  << sx << "\t\t" 
                  << c2x << "\t\t" 
                  << s2x << "\n";
    }
}

// Function to verify the base case
void verifyBaseCase() {
    const double epsilon = 1e-6;
    const double testValue = epsilon / 2.0;  // A value smaller than epsilon
    
    double cResult = calculateC(testValue, epsilon);
    double sResult = calculateS(testValue, epsilon);
    double cExpected = 1.0/testValue + testValue/6.0;
    double sExpected = 1.0 + (testValue * testValue) / 2.0;
    
    std::cout << "\nBase Case Verification (x = " << testValue << "):\n";
    std::cout << "==========================================\n";
    std::cout << "C(x):\n";
    std::cout << "Calculated: " << cResult << "\n";
    std::cout << "Expected:   " << cExpected << "\n";
    std::cout << "Difference: " << std::abs(cResult - cExpected) << "\n\n";
    std::cout << "S(x):\n";
    std::cout << "Calculated: " << sResult << "\n";
    std::cout << "Expected:   " << sExpected << "\n";
    std::cout << "Difference: " << std::abs(sResult - sExpected) << "\n";
}

// Function to test edge cases
void testEdgeCases() {
    const double epsilon = 1e-6;
    const double maxX = std::atan(1.0);
    
    std::cout << "\nEdge Cases:\n";
    std::cout << "==========\n";
    std::cout << "x\t\tC(x)\t\tS(x)\n";
    std::cout << "------------------\n";
    
    // Test values at and near the boundaries
    double testValues[] = {
        -maxX, -maxX + 0.001, -0.001, 0.0, 0.001, maxX - 0.001, maxX
    };
    
    for (double x : testValues) {
        std::cout << x << "\t\t" 
                  << calculateC(x, epsilon) << "\t\t" 
                  << calculateS(x, epsilon) << "\n";
    }
}

int main() {
    // Test both functions with various inputs
    testFunctions();
    
    // Verify the base case
    verifyBaseCase();
    
    // Test edge cases
    testEdgeCases();
    
    return 0;
}
