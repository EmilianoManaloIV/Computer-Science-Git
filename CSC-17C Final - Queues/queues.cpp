#include <iomanip>
#include <iostream>
#include <queue>
#include <random>
#include <vector>
using namespace std;
//---RNG SETUP---
random_device rd;
mt19937 gen(rd()); // Mersenne Twister RNG
uniform_int_distribution<> arr(30, 90); // Arrival times
uniform_int_distribution<> tel(30, 180); // Teller one processes
//---GLOBAL VALUES---
class Customer {
public:
int initialTime;
Customer(int t) { initialTime = t; }
};
class Teller {
public:
int secondsPerCustomer;
bool isRandom = false;
Teller(int s) { secondsPerCustomer = s; }
Teller(int s, bool b) {
secondsPerCustomer = s;
isRandom = b;
}
void startServing(queue<Customer> &line, const int time, int &totalTime,
int &customersServed) {
if (isRandom == true)
secondsPerCustomer = tel(gen);
if (!line.empty() && time % secondsPerCustomer == 0) {
totalTime += abs(time - line.front().initialTime);
line.pop();
customersServed++;
}
}
};
void regSim() {
queue<Customer> line;
vector<Teller> tellers = {Teller(60), Teller(120), Teller(80)};
int maxQueueSize = 0;
int totalTime = 0;
int customersServed = 0;
for (int i = 0; i < 28800; i++) {
if (i % 60 == 0) {
line.push(Customer(i));
line.push(Customer(i));
line.push(Customer(i));
line.push(Customer(i));
}
for (auto &teller : tellers)
teller.startServing(line, i, totalTime, customersServed);
if (line.size() > 4) {
tellers.push_back(Teller(60));
}
if (line.empty() && tellers.size() > 3) {
tellers.pop_back();
}
if (line.size() > maxQueueSize)
maxQueueSize = line.size();
}
cout << fixed << setprecision(2);
cout << "\n===== Simulation Results =====\n";
cout << left << setw(25) << "Total Wait Time:" << totalTime << " seconds\n";
if (customersServed > 0)
cout << left << setw(25)
<< "Average Wait Time:" << (float)totalTime / customersServed
<< " seconds\n";
cout << left << setw(25) << "Max Queue Size:" << maxQueueSize
<< " customers\n";
cout << "===============================\n";
}
void ranSim() {
queue<Customer> line;
vector<Teller> tellers = {Teller(60, true), Teller(120, true),
Teller(80, true)};
int maxQueueSize = 0;
int totalTime = 0;
int customersServed = 0;
int initialArrival = 60;
for (int i = 0; i < 28800; i++) {
if (i % initialArrival == 0) {
line.push(Customer(i));
line.push(Customer(i));
line.push(Customer(i));
line.push(Customer(i));
initialArrival = arr(gen);
}
for (auto &teller : tellers)
teller.startServing(line, i, totalTime, customersServed);
if (line.size() > 4) {
tellers.push_back(Teller(60, true));
}
if (line.empty() && tellers.size() > 3) {
tellers.pop_back();
}
if (line.size() > maxQueueSize)
maxQueueSize = line.size();
}
cout << fixed << setprecision(2);
cout << "\n===== Simulation Results =====\n";
cout << left << setw(25) << "Total Wait Time:" << totalTime << " seconds\n";
if (customersServed > 0)
cout << left << setw(25)
<< "Average Wait Time:" << (float)totalTime / customersServed
<< " seconds\n";
cout << left << setw(25) << "Max Queue Size:" << maxQueueSize
<< " customers\n";
cout << "===============================\n";
}
int main() {
regSim();
ranSim();
return 0;
}