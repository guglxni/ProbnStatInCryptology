#include <iostream>
#include <vector>

using namespace std;

class HuffmanEncoder {
public:
  HuffmanEncoder(vector<int> frequencies) {
    // Create a priority queue of nodes.
    vector<Node> nodes;
    for (int i = 0; i < frequencies.size(); i++) {
      nodes.push_back(Node(i, frequencies[i]));
    }

    // While there are more than one nodes in the queue, merge the two nodes with the
    // smallest weights.
    while (nodes.size() > 1) {
      Node* left = nodes.front();
      nodes.erase(nodes.begin());
      Node* right = nodes.front();
      nodes.erase(nodes.begin());

      nodes.push_back(Node(left->weight + right->weight, left, right));
    }

    // The root node is the only node left in the queue.
    root = nodes.front();
  }

  vector<bool> encode(string message) {
    // Create a vector of bits to store the encoded message.
    vector<bool> encoded_message;

    // Iterate over the message and encode each character.
    for (char c : message) {
      encoded_message.push_back(root->encode(c));
    }

    return encoded_message;
  }

private:
  struct Node {
    int weight;
    int character;
    Node* left;
    Node* right;

    Node(int weight, int character) {
      this->weight = weight;
      this->character = character;
      this->left = nullptr;
      this->right = nullptr;
    }

    Node(int weight, Node* left, Node* right) {
      this->weight = weight;
      this->character = -1;
      this->left = left;
      this->right = right;
    }

    bool encode(char c) {
      if (this->character == c) {
        return true;
      } else if (this->left != nullptr) {
        return this->left->encode(c);
      } else {
        return this->right->encode(c);
      }
    }
  };

  Node* root;
};

int main() {
  // Create a vector of frequencies for the characters in the message "Hello, world!".
  vector<int> frequencies = {8, 1, 12, 4, 1};

  // Create a Huffman encoder.
  HuffmanEncoder encoder(frequencies);

  // Encode the message.
  vector<bool> encoded_message = encoder.encode("Hello, world!");

  // Print the encoded message.
  for (bool bit : encoded_message) {
    cout << bit;
  }

  return 0;
}
