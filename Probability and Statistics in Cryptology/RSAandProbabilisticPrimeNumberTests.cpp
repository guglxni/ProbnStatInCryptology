#include <iostream>
#include <vector>

using namespace std;

int miller_rabin(int n, int k) {
  if (n == 2) {
    return 1;
  }

  if (n % 2 == 0) {
    return 0;
  }

  for (int i = 0; i < k; i++) {
    int a = rand() % (n - 2) + 2;
    int b = pow(a, (n - 1) / 2) % n;
    if (b == 1 || b == n - 1) {
      continue;
    }

    for (int j = 0; j < (n - 2) / 2; j++) {
      b = pow(b, 2) % n;
      if (b == n - 1) {
        break;
      }

      if (b == 1) {
        return 0;
      }
    }
  }

  return 1;
}

void generate_prime(int n) {
  while (true) {
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
      bool is_prime = true;
      for (int j = 0; j < primes.size(); j++) {
        if (i % primes[j] == 0) {
          is_prime = false;
          break;
        }
      }

      if (is_prime) {
        primes.push_back(i);
      }
    }

    if (primes.size() >= 2) {
      int p = primes[rand() % primes.size()];
      int q = primes[rand() % primes.size()];
      int n = p * q;

      if (miller_rabin(n, 10) == 1) {
        cout << "Generated prime: " << n << endl;
        return;
      }
    }
  }
}

int main() {
  generate_prime(1000);
  return 0;
}
