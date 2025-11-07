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

bool search(const string& word) {

    TrieNode* node = root;
    for(char ch : word) {
        int index = ch - 'a';
        if( !node->children[index])
            return false;
        node = node->children[index];
    }
    return node->isEndOfWord;
}

bool deleteWord(const string& word) {

     return deleteHelper(root, word, 0);
}

    private:
bool deleteHelper(TrieNode* node, const string& word, int depth)

     if(!node)
     return false;

     if(depth == word.size()){
        if(!node->isEndOfWord)
           return false;
           node->isEndOfWord = false;
           return isEmpty(node);
    }

    int index = word[depth] - 'a';
    if(deleteHelper(node->children[index], word, depth + 1)){
      delete node->children[index];
      node->children[index] = nullptr;
      return !node->isEndOfWord && isEmpty(node);
    }

    return false;
}

bool isEmpty(TrieNode* node){
     for(int i = 0; i < 26; i++)
        if(node->children[i] return false;
     return true;
}
};



int main() {

    Trie trie;

    trie.insert("apple");
    trie.insert("art");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("battle");
    trie.insert("ball");
    trie.insert("ballot");

    cout << "Search 'apple' : " << (trie.search("apple")? "Found" : "Not Found") << endl;
    cout << "Search 'app' : " << (trie.search("app")? "Found" : "Not Found" ) << endl;
    cout << "Search 'battle' : " << (trie.search("battle")? "Found" : "Not Found") << endl;
    cout << "Search 'bat' : " << (trie.search("bat")? "Found" : "Not Found" << endl;
    cout << "Search 'banana' : " << (trie.search("banana")? "Found" : "Not Found") << endl;
    cout << "Searcg 'appearance' : " << (trie.search("appearance")? "Found" : "Not Found") << endl;

    trie.deleteWord("app");
    trie.deleteWord("bat");

    cout << "Search 'app' : " << (trie.search("app")? "Found" : "Not Found") << endl;
    cout << "Search 'bat' : " << (trie.search("bat")? "Found" : "Not Found") << endl;
    

    return 0;
}

