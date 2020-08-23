#include <string>
#include <unordered_map>
#include <vector>


struct TrieNode {
    TrieNode() : children({}), is_end_of_word(false) {
    }

    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        TrieNode* p = root;
        for (auto& w : word) {
            if (p->children.find(w) == p->children.end()) {
                p->children[w] = new TrieNode();
            }
            p = p->children.at(w);
        }
        p->is_end_of_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        TrieNode* p = root;
        for (auto& w : word) {
            if (p->children.find(w) == p->children.end()) {
                return false;
            }
            p = p->children.at(w);
        }
        return p->is_end_of_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto& w : prefix) {
            if (p->children.find(w) == p->children.end()) {
                return false;
            }
            p = p->children.at(w);
        }
        return true;
    }

private:
    TrieNode* root;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */