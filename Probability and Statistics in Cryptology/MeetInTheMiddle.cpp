#include <iostream>

using namespace std;

class DES {
public:
  DES() {}

  vector<int> encrypt(vector<int> plaintext, vector<int> key) {
    vector<int> ciphertext;

    for (int round = 0; round < 16; round++) {
      // Apply the round function to the plaintext.
      vector<int> round_function_output = round_function(plaintext, key);

      // XOR the round function output with the subkey.
      ciphertext = xor_vectors(round_function_output, key);
    }

    return ciphertext;
  }

private:
  vector<int> round_function(vector<int> state, vector<int> key) {
    vector<int> output;

    // Apply the S-boxes to the state.
    for (int i = 0; i < 8; i++) {
      output.push_back(s_box(state[i]));
    }

    // Permute the output.
    output = permute_vector(output, {1, 5, 2, 0, 3, 7, 4, 6});

    // XOR the output with the key.
    output = xor_vectors(output, key);

    return output;
  }

  int s_box(int input) {
    int row = (input >> 4) & 0xf;
    int column = input & 0xf;

    int s_box_value = s_boxes[row][column];

    return s_box_value;
  }

  vector<int> permute_vector(vector<int> input, vector<int> permutation) {
    vector<int> output;

    for (int i = 0; i < permutation.size(); i++) {
      output.push_back(input[permutation[i] - 1]);
    }

    return output;
  }

  vector<int> s_boxes = {
      14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
      0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 5, 9, 3, 8, 11,
      4, 1, 14, 8, 13, 6, 2, 15, 10, 9, 3, 7, 5, 0, 12, 11,
      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
      1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 5, 2, 12, 11,
      7, 13, 14, 3, 0, 6, 9, 1, 10, 8, 12, 2, 5, 4, 15, 11,
      9, 14, 15, 4, 3, 2, 12, 0, 7, 10, 1, 8, 5, 6, 13, 11,
      2, 11, 1, 10, 13, 8, 12, 4, 7, 6, 15, 0, 9, 3, 5, 14,
      3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 8, 6, 0, 7, 4, 13};
}
