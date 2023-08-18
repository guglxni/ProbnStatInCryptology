#include <iostream>
#include <vector>

using namespace std;

class PRNG {
public:
  PRNG(int seed) {
    m_state = seed;
  }

  int next_int() {
    m_state = (m_state * 214013 + 2531011) % 2147483647;
    return m_state;
  }

private:
  int m_state;
};

int main() {
  // Create a PRNG with a seed of 1.
  PRNG prng(1);

  // Generate 1000 random numbers.
  vector<int> random_numbers;
  for (int i = 0; i < 1000; i++) {
    random_numbers.push_back(prng.next_int());
  }

  // Calculate the frequency of each number.
  vector<int> frequencies(100, 0);
  for (int number : random_numbers) {
    frequencies[number]++;
  }

  // Check the frequency of each number.
  for (int i = 0; i < 100; i++) {
    if (frequencies[i] < 50 || frequencies[i] > 51) {
      cout << "The frequency of the number " << i << " is not between 50 and 51." << endl;
      return 1;
    }
  }

  // The PRNG passed the frequency test.
  cout << "The PRNG passed the frequency test." << endl;

  return 0;
}
