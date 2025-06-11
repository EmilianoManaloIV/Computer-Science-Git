#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
float h(float);
float g(float);
stack<float> sineStack;
stack<float> cosStack;
int main(int argc, char **argv) {
cout << "Hyperbolic Sine/Cosine Function Call Analysis" << endl;
cout << "=============================================" << endl;
cout << left << setw(10) << "Angle" << setw(15) << "sinh(x)" << setw(15)
<< "Our h(x)" << setw(12) << "Sine Calls" << setw(18) << "Cosine Calls"
<< setw(12) << "Difference" << endl;
cout << string(82, '-') << endl;
for (float i = -1.0; i <= 1.0; i += 0.1) {
stack<float> clear;
sineStack.swap(clear);
cosStack.swap(clear);
cout << fixed << setprecision(1);
cout << left << setw(10) << i;
cout << setprecision(6);
cout << setw(15) << sinh(i) << setw(15) << h(i) << setw(12)
<< sineStack.size() << setw(18) << cosStack.size() << setw(12)
<< abs(sinh(i) - h(i)) << endl;
}
return 0;
}
float h(float angR) {
float tol = 1e-6;
sineStack.push(angR); // Track hyperbolic sine calls only
if (angR > -tol && angR < tol)
return angR + angR * angR * angR / 6;
return 2 * h(angR / 2) * g(angR / 2);
}
float g(float angR) {
cosStack.push(angR);
float tol = 1e-6;
if (angR > -tol && angR < tol)
return 1 + angR * angR / 2;
float b = h(angR / 2);
return 1 + 2 * b * b;
}