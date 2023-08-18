#include <iostream>
#include <vector>

using namespace std;

class DiffieHellman {
public:
  DiffieHellman(int p, int g) {
    m_p = p;
    m_g = g;
  }

  vector<int> compute_shared_secret(int a, int b) {
    vector<int> shared_secret;

    shared_secret.push_back(pow(b, a) % m_p);
    shared_secret.push_back(pow(a, b) % m_p);

    return shared_secret;
  }

private:
  int m_p;
  int m_g;
};

int main() {
  // Choose a prime number p and a generator g.
  int p = 1009;
  int g = 7;

  // Alice generates a private key a.
  int a = 5;

  // Bob generates a private key b.
  int b = 8;

  // Alice computes the shared secret S.
  DiffieHellman alice(p, g);
  vector<int> alice_shared_secret = alice.compute_shared_secret(a, b);

  // Bob computes the shared secret S.
  DiffieHellman bob(p, g);
  vector<int> bob_shared_secret = bob.compute_shared_secret(b, a);

  // Check that Alice and Bob have the same shared secret.
  if (alice_shared_secret == bob_shared_secret) {
    cout << "Alice and Bob have the same shared secret." << endl;
  } else {
    cout << "Alice and Bob do not have the same shared secret." << endl;
  }

  return 0;
}
