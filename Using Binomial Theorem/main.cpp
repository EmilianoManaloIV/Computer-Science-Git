#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//--- Function Prototypes ---
int mrkRand(int seed);
double mrkRand01(int seed = 0);
double binomialCoeff(int n, int k);
double binomialProbability(int n, int k, double p_head);
double simulateWithMrkRand(int n_tosses, int k_tails, double p_tail, int trials, int seed = 42);

int main() {
    const int n = 4;
    const int k = 1;
    const int trials = 10000;

    // Exact values using Binomial Theorem
    double fair_exact = binomialProbability(n, k, 0.5);
    double biased_exact = binomialProbability(n, k, 0.6);

    // Simulation using mrkRand
    double fair_sim = simulateWithMrkRand(n, k, 0.5, trials, 12345);
    double biased_sim = simulateWithMrkRand(n, k, 0.4, trials, 12345);

    cout << fixed << setprecision(5);
    cout << "Flipping 4 coins and getting exactly 1 tail:\n";
    cout << "Fair Coin - Exact:    " << fair_exact << "\n";
    cout << "Fair Coin - Simulated:" << fair_sim << "\n";
    cout << "Biased Coin - Exact:    " << biased_exact << "\n";
    cout << "Biased Coin - Simulated:" << biased_sim << "\n";

    return 0;
}

//--- Linear Congruential Generator (LCG) ---
int mrkRand(int seed){
    unsigned int a = 31051;
    unsigned int c = 997;
    unsigned int shrt = (1 << 15) - 1;
    unsigned int m = (1U << 31) - 1;
    static int Xn = 30937;
    static int cnt = 0;
    if (cnt == 0 && seed <= shrt) Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m;
    return Xn;
}

// Convert random int to [0, 1)
double mrkRand01(int seed) {
    return static_cast<double>(mrkRand(seed)) / ((1U << 31) - 1);
}

// Binomial coefficient C(n, k)
double binomialCoeff(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    double res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1.0) / i;
    }
    return res;
}

// Binomial probability P(X = k)
double binomialProbability(int n, int k, double p_head) {
    double p_tail = 1 - p_head;
    return binomialCoeff(n, k) * pow(p_tail, k) * pow(p_head, n - k);
}

// Simulate tossing n coins, count trials with exactly k tails
double simulateWithMrkRand(int n_tosses, int k_tails, double p_tail, int trials, int seed) {
    int match_count = 0;
    for (int t = 0; t < trials; ++t) {
        int tails = 0;
        for (int i = 0; i < n_tosses; ++i) {
            if (mrkRand01(seed) < p_tail) tails++;
        }
        if (tails == k_tails) match_count++;
    }
    return static_cast<double>(match_count) / trials;
}
