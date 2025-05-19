#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>

// Function to calculate theoretical probability using binomial theorem
double calculateTheoreticalProbability(double p, int n) {
    // For all bits being filled, we use p^n
    return std::pow(p, n);
}

// Function to simulate one trial of selecting n bits
bool simulateTrial(double p, int n, std::mt19937& rng) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    
    // Check if all n bits are filled
    for (int i = 0; i < n; i++) {
        if (dist(rng) > p) {
            return false;  // If any bit is empty, trial fails
        }
    }
    return true;  // All bits are filled
}

int main() {
    const double p = 0.4;  // Probability of a bit being filled (40%)
    const int n = 5;       // Number of bits to select
    const int numTrials = 1000000;  // Number of simulation trials
    
    // Set up random number generator
    std::random_device rd;
    std::mt19937 rng(rd());
    
    // Calculate theoretical probability
    double theoreticalProb = calculateTheoreticalProbability(p, n);
    
    // Run simulation
    int successfulTrials = 0;
    for (int i = 0; i < numTrials; i++) {
        if (simulateTrial(p, n, rng)) {
            successfulTrials++;
        }
    }
    
    // Calculate empirical probability
    double empiricalProb = static_cast<double>(successfulTrials) / numTrials;
    
    // Output results
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Simulation Results:\n";
    std::cout << "-------------------\n";
    std::cout << "Theoretical Probability: " << theoreticalProb << "\n";
    std::cout << "Empirical Probability:   " << empiricalProb << "\n";
    std::cout << "Number of Trials:        " << numTrials << "\n";
    std::cout << "Successful Trials:       " << successfulTrials << "\n";
    
    return 0;
}
