#include <iostream>
#include <vector>

using namespace std;

class BB84 {
public:
  BB84() {}

  vector<int> encode(vector<int> plaintext) {
    vector<int> encoded_bits;

    for (int i = 0; i < plaintext.size(); i++) {
      encoded_bits.push_back(plaintext[i] ^ rand() % 2);
    }

    return encoded_bits;
  }

  vector<int> decode(vector<int> encoded_bits) {
    vector<int> decoded_bits;

    for (int i = 0; i < encoded_bits.size(); i++) {
      decoded_bits.push_back(encoded_bits[i] ^ rand() % 2);
    }

    return decoded_bits;
  }
};

int main() {
  vector<int> plaintext = {0, 1, 0, 1};
  BB84 bb84;
  vector<int> encoded_bits = bb84.encode(plaintext);
  vector<int> decoded_bits = bb84.decode(encoded_bits);

  for (int i = 0; i < decoded_bits.size(); i++) {
    cout << decoded_bits[i];
  }

  return 0;
}
