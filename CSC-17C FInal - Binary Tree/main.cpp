#include "MyTree.h"
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;
int teleHash512(string);
string genI();
int maxCol(int, int);
int stringToIntASCII(const string &input) {
  string combined = "";
  for (char c : input) {
    combined += to_string(static_cast<int>(c));
  }
  return stoi(combined); // Be careful: this fails if the string is too long
}
map<char, int> teleKey = {
    {'A', 2}, {'B', 2}, {'C', 2}, {'D', 3}, {'E', 3}, {'F', 3}, {'G', 4},
    {'H', 4}, {'I', 4}, {'J', 5}, {'K', 5}, {'L', 5}, {'M', 6}, {'N', 6},
    {'O', 6}, {'P', 7}, {'Q', 7}, {'R', 7}, {'S', 7}, {'T', 8}, {'U', 8},
    {'V', 8}, {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}};

int main() {
  unordered_map<int, int> bucketStat;
  list<string> hashTable[512];
  MyTree tree;
  for (int i = 0; i < 511; i++) {
    string I = genI();
    tree.insert(teleHash512(I));
    hashTable[teleHash512(I)].push_back(I);
  }
  for (int i = 0; i < 511; i++) {
    bucketStat[hashTable[i].size()]++;
  }
  for (const auto &pair : bucketStat) {
    cout << "Bucket " << pair.first << " has " << pair.second
         << " elements...P = " << static_cast<float>(pair.second) / 512 << endl;
  }
  cout << "Amount Of Nodes: " << tree.countNodes() << endl;
  cout << "Depth: " << tree.getHeight() << endl;
  tree.print();
  return 0;
}

int teleHash512(string toHash) {
  ostringstream comb;
  for (char c : toHash) {
    c = toupper(c);
    comb << teleKey[c];
  }
  return stoi(comb.str()) % 512;
}

string genI() {
  static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
  static std::uniform_int_distribution<int> dist('A', 'Z');
  string I;
  for (int i = 0; i < 3; ++i) {
    I += static_cast<char>(dist(rng));
  }
  return I;
}