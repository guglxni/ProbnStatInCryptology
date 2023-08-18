#include <iostream>
#include <vector>

using namespace std;

class PRNG {
public:
  PRNG() {}

  int next_int() {
    // Generate a random number from the physical random number generator.
    int random_number = rand();

    // Return the random number.
    return random_number;
  }

  vector<int> next_ints(int n) {
    // Generate n random numbers from the physical random number generator.
    vector<int> random_numbers;
    for (int i = 0; i < n; i++) {
      random_numbers.push_back(rand());
    }

    // Return the random numbers.
    return random_numbers;
  }
};

int main() {
  // Create a PRNG object.
  PRNG prng;

  // Generate a random number.
  int random_number = prng.next_int();
  cout << "The random number is: " << random_number << endl;

  // Generate 10 random numbers.
  vector<int> random_numbers = prng.next_ints(10);
  for (int random_number : random_numbers) {
    cout << random_number << " ";
  }
  cout << endl;

  return 0;
}
