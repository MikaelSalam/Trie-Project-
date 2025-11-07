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


class Trie {

      private:
              TrieNode* root;

      public:
              Trie() {
                   root = new TrieNode();
              }

void insert(const string& word) {

     TrieNode* node = root;
     for( char ch : word) {
         int index = ch - 'a';
         if(!node->children[index])
            node->children[index] = newTrieNode();
         node = node->children[index];
     }
     node->isEndOfWord = true;
     node->frequency++;
}
};



int main() {




    return 0;
}
