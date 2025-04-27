#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function prototypes
double b10Factorial(int);
double b10Permutation(int, int);
double b10Permutation_r(int, int);
double b10Combination(int, int);
double b10Combination_r(int, int);
void printRow(int, int);

int main()
{
    cout << "P -> Permutation(Order Matters)" << endl;
    cout << "C -> Combination(Order does not matter)" << endl;
    cout << "Rep -> with replacement" << endl;
    cout << "no Rep -> no replacement" << endl;
    cout << "N -> Number of total elements" << endl;
    cout << "M -> Number of elements to take from the total" << endl << endl;
    cout << " N M P Rep P no Rep C Rep C no Rep" << endl;
    cout << " N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)" << endl << endl;

    for (int i = 2; i <= 26; i++)
    {
        cout << endl;
        for (int l = 0; l <= i; l++)
        {
            printRow(i, l);
        }
    }
    return 0;
}

void printRow(int n, int m)
{
    cout << left;
    cout << setprecision(3);
    cout << setw(3) << n << setw(3) << m;

    cout << setw(12) << pow(10.0, b10Permutation_r(n, m))
         << setw(12) << pow(10.0, b10Permutation(n, m))
         << setw(12) << pow(10.0, b10Combination_r(n, m))
         << setw(12) << pow(10.0, b10Combination(n, m))
         << endl;
}

double b10Factorial(int n)
{
    // 0! = 1, handle the case for n <= 0
    if (n <= 0) return 0;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += log10(i);  // Sum the logarithms of factorial numbers
    }
    return sum;
}

double b10Permutation(int n, int m)
{
    return b10Factorial(n) - b10Factorial(n - m);
}

double b10Permutation_r(int n, int m)
{
    return m * log10(n);
}

double b10Combination(int n, int m)
{
    return b10Factorial(n) - (b10Factorial(m) + b10Factorial(n - m));
}

double b10Combination_r(int n, int m)
{
    return b10Factorial(n + m - 1) - (b10Factorial(m) + b10Factorial(n - 1));
}
