#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

string encrypt(string plaintext, string key) {
  string ciphertext;
  for (int i = 0; i < plaintext.length(); i++) {
    int plaintext_index = plaintext[i] - 'a';
    int key_index = key[i % key.length()] - 'a';
    ciphertext += (char) (plaintext_index + key_index);
  }
  return ciphertext;
}

string decrypt(string ciphertext, string key) {
  string plaintext;
  for (int i = 0; i < ciphertext.length(); i++) {
    int ciphertext_index = ciphertext[i] - 'a';
    int key_index = key[i % key.length()] - 'a';
    plaintext += (char) (ciphertext_index - key_index);
  }
  return plaintext;
}

int main() {
  string plaintext = "This is a plaintext message.";
  string key = "secretkey";
  string ciphertext = encrypt(plaintext, key);
  string deciphered_text = decrypt(ciphertext, key);

  cout << "Plaintext: " << plaintext << endl;
  cout << "Key: " << key << endl;
  cout << "Ciphertext: " << ciphertext << endl;
  cout << "Deciphered text: " << deciphered_text << endl;

  return 0;
}
