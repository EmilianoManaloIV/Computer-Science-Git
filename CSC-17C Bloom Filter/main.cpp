#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <map>
#include <random>

//Global Variables
std::string added_names[50] = {
    "Alice", "Bob", "Carol", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack",
    "Karen", "Liam", "Mia", "Noah", "Olivia", "Paul", "Quinn", "Rachel", "Sam", "Tina",
    "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zoe", "Brian", "Chloe", "Derek", "Ella",
    "Felix", "Gina", "Hugo", "Isla", "Jason", "Kate", "Leo", "Molly", "Nate", "Opal",
    "Peter", "Quinn", "Rose", "Steve", "Tara", "Uri", "Vince", "Willow", "Xena", "Yolanda"
};
std::string test_names[50] = {
    "Apple", "Banana", "Cactus", "Dolphin", "Eclipse", "Falcon", "Galaxy", "Horizon", "Igloo", "Jaguar",
    "Kite", "Lantern", "Mango", "Nebula", "Orbit", "Prism", "Quartz", "Rocket", "Satellite", "Tulip",
    "Umbrella", "Volcano", "Walnut", "Xenon", "Yacht", "Zebra", "Anchor", "Breeze", "Canyon", "Drift",
    "Ember", "Frost", "Glacier", "Harbor", "Island", "Jungle", "Keystone", "Lagoon", "Meadow", "Nimbus",
    "Oasis", "Pebble", "Quiver", "Rapids", "Summit", "Timber", "Underpass", "Valley", "Wharf", "Zenith"
};
//Function Prototypes
unsigned int ELFHash(const std::string&);
unsigned int DJBHash(const std::string&);
void hashIt(const std::string&, std::vector<bool>&);
bool lookUp(const std::string&, std::vector<bool>&);
std::string getRandomName(const std::string names[], size_t size);

int main()
{
    int size = 15;
    int inputSize = 15;
    float falseInputs = 50;
    float falsePos = 0;
    std::vector<bool> bitVector(size, false);
    std::string input_word;

    std::cout << "--- Add items to Bloom Filter ---" << std::endl;
     for(int i = 0; i < inputSize; i++)
    {
        hashIt(getRandomName(added_names, 50), bitVector);
    }

    std::cout << "\n--- Lookup items in Bloom Filter ---" << std::endl;
    for(int i = 0; i < falseInputs; i++)
    {
        if(lookUp(test_names[i], bitVector))
        {
            falsePos++;
        }
    }
    std::cout << "CALCULATED ESTIMATE OF FALSE POSITIIVES %: " << pow((1 - exp(-1*2*inputSize/size)),2) << std::endl;
    std::cout << "ACTUAL FALSE POSITIVES %: " << falsePos/falseInputs << std::endl;
    return 0;
}

unsigned int ELFHash(const std::string& str_ref) // Changed parameter name to avoid conflict with str pointer inside
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;
   unsigned int length = str_ref.length();
   const char* c_str = str_ref.c_str();

   for (i = 0; i < length; ++c_str, ++i)
   {
      hash = (hash << 4) + (*c_str);

      if ((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }

      hash &= ~x;
   }

   return hash;
} 

unsigned int DJBHash(const std::string& str_ref)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;
   unsigned int length = str_ref.length();
   const char* c_str = str_ref.c_str();

   for (i = 0; i < length; ++c_str, ++i)
   {
      hash = ((hash << 5) + hash) + (*c_str); // hash * 33 + c
   }

   return hash;
} 

void hashIt(const std::string& str_ref, std::vector<bool>& bitVector)
{
    unsigned int hash1 = ELFHash(str_ref);
    unsigned int hash2 = DJBHash(str_ref);

    unsigned int index1 = hash1 % bitVector.size();
    unsigned int index2 = hash2 % bitVector.size();
    
    bitVector[index1] = true;
    bitVector[index2] = true;
}

bool lookUp(const std::string& str_ref, std::vector<bool>& bitVector)
{
     unsigned int hash1 = ELFHash(str_ref);
    unsigned int hash2 = DJBHash(str_ref);

    unsigned int index1 = hash1 % bitVector.size();
    unsigned int index2 = hash2 % bitVector.size();
    
    return bitVector[index1] && bitVector[index2];
}

std::string getRandomName(const std::string names[], size_t size) {
    if (size == 0) return ""; // Handle empty array
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, size - 1);
    return names[dist(rng)];
}