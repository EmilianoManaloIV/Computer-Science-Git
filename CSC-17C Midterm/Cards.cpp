#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>
#include <map>

// Function to calculate theoretical probabilities for combinations with replacement
void calculateTheoreticalProbabilities() {
    // For combinations with replacement: C(n+r-1, r)
    // Where n = 13 (possible values) and r = 4 (selections)
    // C(13+4-1, 4) = C(16, 4) = 1820 total possible combinations
    
    // Four of a kind (all same value)
    // 13 possible values, only 1 way to get 4 of same value
    double fourOfAKind = 13.0 / 1820.0;
    
    // Three of a kind
    // 13 possible values for the three, 12 remaining values for the fourth
    // C(4,3) ways to arrange the three of a kind
    double threeOfAKind = (13.0 * 12.0 * 4.0) / 1820.0;
    
    // Two pairs
    // C(13,2) ways to choose the two values, C(4,2) ways to arrange the pairs
    double twoPairs = (78.0 * 6.0) / 1820.0;
    
    // One pair
    // 13 possible values for the pair, C(4,2) ways to arrange the pair
    // C(12,2) ways to choose the other two values
    double onePair = (13.0 * 6.0 * 66.0) / 1820.0;
    
    std::cout << "Theoretical Probabilities (with replacement):\n";
    std::cout << "----------------------------------------\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Four of a kind:  " << fourOfAKind << "\n";
    std::cout << "Three of a kind: " << threeOfAKind << "\n";
    std::cout << "Two pairs:       " << twoPairs << "\n";
    std::cout << "One pair:        " << onePair << "\n\n";
}

// Function to simulate drawing 4 values with replacement
std::string simulateHand(std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(0, 12);  // 13 possible values (0-12)
    
    // Draw 4 values with replacement
    std::vector<int> hand(4);
    for (int i = 0; i < 4; i++) {
        hand[i] = dist(rng);
    }
    
    // Count occurrences of each value
    std::map<int, int> valueCount;
    for (int value : hand) {
        valueCount[value]++;
    }
    
    // Determine the hand type
    int pairs = 0;
    bool hasThree = false;
    bool hasFour = false;
    
    for (const auto& pair : valueCount) {
        if (pair.second == 4) hasFour = true;
        else if (pair.second == 3) hasThree = true;
        else if (pair.second == 2) pairs++;
    }
    
    if (hasFour) return "Four of a kind";
    if (hasThree) return "Three of a kind";
    if (pairs == 2) return "Two pairs";
    if (pairs == 1) return "One pair";
    return "No pair";
}

int main() {
    const int numTrials = 1000000;
    
    // Set up random number generator
    std::random_device rd;
    std::mt19937 rng(rd());
    
    // Calculate and display theoretical probabilities
    calculateTheoreticalProbabilities();
    
    // Initialize counters for each hand type
    std::map<std::string, int> handCounts;
    handCounts["Four of a kind"] = 0;
    handCounts["Three of a kind"] = 0;
    handCounts["Two pairs"] = 0;
    handCounts["One pair"] = 0;
    handCounts["No pair"] = 0;
    
    // Run simulation
    for (int i = 0; i < numTrials; i++) {
        std::string hand = simulateHand(rng);
        handCounts[hand]++;
    }
    
    // Display simulation results
    std::cout << "Simulation Results (" << numTrials << " trials):\n";
    std::cout << "--------------------------------\n";
    for (const auto& pair : handCounts) {
        double probability = static_cast<double>(pair.second) / numTrials;
        std::cout << std::fixed << std::setprecision(6);
        std::cout << pair.first << ": " << probability 
                  << " (" << pair.second << " occurrences)\n";
    }
    
    return 0;
}
