#include <iostream>
#include <string>
using namespace std;

struct TrieNode {

      TrieNode* children[26];
      bool isEndOfWord;
      int frequency;

      TrieNode(){
      isEndOfWorld = false;
      frequency = 0;
      for(int i = 0 ; i < 26 ; i++)
          children[i] = nullptr;
      }
};

int main() {




    return 0;
}
