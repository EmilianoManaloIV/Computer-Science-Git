#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate g(x) recursively
// What: Calculates g(x) using the given recursive formula
// How: Uses base case for small x and recursive formula for larger x
// Why: Implements the mathematical function g(2x) = 2g(x)/(1 + g(x)^2)
double calculateG(double x, double epsilon = 1e-6) {
    // Base case: when |x| < epsilon
    if (std::abs(x) < epsilon) {
        return x - (x * x * x) / 6.0;
    }
    
    // Recursive case: g(2x) = 2g(x)/(1 + g(x)^2)
    // We need to work backwards from 2x to x
    double gx = calculateG(x/2.0, epsilon);
    return (2.0 * gx) / (1.0 + gx * gx);
}

// Function to test the recursive function
void testFunction() {
    const double epsilon = 1e-6;
    const double step = 0.1;
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Testing g(x) function\n";
    std::cout << "====================\n";
    std::cout << "x\t\tg(x)\t\t2g(x/2)/(1+g(x/2)^2)\tDifference\n";
    std::cout << "--------------------------------------------------------\n";
    
    // Test values from -1 to 1 with step 0.1
    for (double x = -1.0; x <= 1.0; x += step) {
        double gx = calculateG(x, epsilon);
        double gx2 = calculateG(x/2.0, epsilon);
        double formula = (2.0 * gx2) / (1.0 + gx2 * gx2);
        double difference = std::abs(gx - formula);
        
        std::cout << x << "\t\t" 
                  << gx << "\t\t" 
                  << formula << "\t\t" 
                  << difference << "\n";
    }
}

// Function to verify the base case
void verifyBaseCase() {
    const double epsilon = 1e-6;
    const double testValue = epsilon / 2.0;  // A value smaller than epsilon
    
    double result = calculateG(testValue, epsilon);
    double expected = testValue - (testValue * testValue * testValue) / 6.0;
    
    std::cout << "\nBase Case Verification (x = " << testValue << "):\n";
    std::cout << "==========================================\n";
    std::cout << "Calculated: " << result << "\n";
    std::cout << "Expected:   " << expected << "\n";
    std::cout << "Difference: " << std::abs(result - expected) << "\n";
}

// Function to test edge cases
void testEdgeCases() {
    const double epsilon = 1e-6;
    
    std::cout << "\nEdge Cases:\n";
    std::cout << "==========\n";
    std::cout << "x\t\tg(x)\n";
    std::cout << "------------------\n";
    
    // Test values at and near the boundaries
    double testValues[] = {
        -1.0, -0.999, -0.001, 0.0, 0.001, 0.999, 1.0
    };
    
    for (double x : testValues) {
        std::cout << x << "\t\t" << calculateG(x, epsilon) << "\n";
    }
}

int main() {
    // Test the function with various inputs
    testFunction();
    
    // Verify the base case
    verifyBaseCase();
    
    // Test edge cases
    testEdgeCases();
    
    return 0;
}
