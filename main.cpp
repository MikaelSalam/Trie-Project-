#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {

      TrieNode* children[26];
      bool isEndOfWord;
      int frequency;

      TrieNode() {
      isEndOfWord = false;
      frequency = 0;
      for(int i = 0 ; i < 26 ; i++)
          children[i] = nullptr;
      }
};

struct WordFreq{
       string word;
       int frequency;
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
            node->children[index] = new TrieNode();
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

vector<string> autocomplete(const string& prefix) {

    TrieNode* node = root;
    for(char ch : prefix) {
       int index = ch - 'a'
       if(!node->children[index])
       return {};
       node = node->children[index];
    }

    vector<string> suggestions;
    collectWords(node , prefix , suggestions);
      return suggestions;
}

vector<WordFreq> autocompleteWithFrequency(const string& prefix){

     TrieNode* node = root;
     for(char ch : prefix){
        int index = ch - 'a';
        if (!node -> children[index]) 
        return {};
        node = node->children[index];
     }

     vector<WordFreq> results;
     collectionWordsWithFrequency(node, prefix , results);
     
     for(size_t i = 0; i < results.size(); i++){
       for(size_t j = i + 1; j < results.size(); j++){
          if(results[j].frequency > results[i].frequency) {
            swap(results[i], results[j]);
          }
        }
     }
     return results;

}
    private:
bool deleteHelper(TrieNode* node, const string& word, int depth){

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
        if(node->children[i]) return false;
     return true;
}

void collectWords(TrieNode* node, string prefix , vector<string>& results) {

     if(!node)
     return;
     if(node->isEndOfWord){
        results.push_back(prefix);
     }

     for(int i = 0; i < 26; i++){
       if(node->children[i]) {
        char nextChar = 'a' + i;
        collectWords(node->children[i], prefix + nextChar, results);
       }
     }
 }

void collectionWordsWithFrequency(TrieNode* node, string prefix, vector<WordFreq>& results) {
   if (!node)
            return;
        if (node->isEndOfWord) {
            results.push_back({prefix, node->frequency});
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char nextChar = 'a' + i;
                collectWordsWithFrequency(node->children[i], prefix + nextChar, results);
            }
        }
 }
};



int main() {

    Trie trie;

    trie.insert("apple");
    trie.insert("art");
    trie.insert("ant");
    trie.insert("app");
    trie.insert("application");
    trie.insert("android");
    trie.insert("appearance");
    trie.insert("bat");
    trie.insert("battle");
    trie.insert("ball");
    trie.insert("ballot");
    trie.insert("battery");
    trie.insert("car");
    trie.insert("carry");
    trie.insert("check");
    trie.insert("change");

    cout << "Search 'apple' : " << (trie.search("apple")? "Found" : "Not Found") << endl;
    cout << "Search 'app' : " << (trie.search("app")? "Found" : "Not Found" ) << endl;
    cout << "Search 'battle' : " << (trie.search("battle")? "Found" : "Not Found") << endl;
    cout << "Search 'bat' : " << (trie.search("bat")? "Found" : "Not Found") << endl;
    cout << "Search 'banana' : " << (trie.search("banana")? "Found" : "Not Found") << endl;
    cout << "Searcg 'appearance' : " << (trie.search("appearance")? "Found" : "Not Found") << endl;

    trie.deleteWord("app");
    trie.deleteWord("bat");

    cout << "Search 'app' : " << (trie.search("app")? "Found" : "Not Found") << endl;
    cout << "Search 'bat' : " << (trie.search("bat")? "Found" : "Not Found") << endl;

    vector<string> suggestions = trie.autocomplete("ap");
    cout << "\nSuggestions for 'ap':\n";
    for (auto& word : suggestions){
        cout << word << endl;
    }

    suggestions = trie.autocomplete("b");
    cout << "\nSuggestions for 'b':\n";
    for (auto&word : suggestions){
        cout << word << endl;
    }

    vector<WordFreq> suggestions = trie.autocompleteWithFrequency("ap");
    cout << "\nSuggestions for 'ap' (ranked by frequency):\n";
    for (auto& entry : suggestions) {
        cout << entry.word << " (frequency: " << entry.frequency << ")\n";
    }

    vector<string> plainSuggestions = trie.autocomplete("b");
    cout << "\nSuggestions for 'b' (ranked by frequency):\n";
    for (auto& entry : suggestions) {
        cout << entry.word <<"(frequency : " << entry.frequency <<")\n";
    }

    plainSuggestions = trie.autocomplete("ch");
    cout << "\nSuggestions for 'ch'(ranked by frequency) :\n";
    for (auto& entry : suggestions) {
        cout << entry.word <<"(frequency : "<< entry.frequency <<")\n ";
    }
    suggestions = trie.autocomplete("ch");
    cout << "\nSuggestions for 'ch':\n";
    for (auto&word : suggestions) {
        cout << word << endl;
    }


    return 0;
}

