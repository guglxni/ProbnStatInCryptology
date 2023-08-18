#include <iostream>

using namespace std;

double calculate_birthday_paradox_probability(int n) {
  double probability = 1.0;
  for (int i = 1; i <= n; i++) {
    probability *= (364.0 - i) / 365.0;
  }
  return 1.0 - probability;
}

int main() {
  int n;
  cout << "Enter the number of people: ";
  cin >> n;

  double probability = calculate_birthday_paradox_probability(n);
  cout << "The probability of two people sharing the same birthday in a group of " << n << " people is " << probability << endl;

  return 0;
}
