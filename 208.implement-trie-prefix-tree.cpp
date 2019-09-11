/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (39.21%)
 * Total Accepted:    187.6K
 * Total Submissions: 477.2K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root.get();
        for (char ch : word) {
            if (nullptr == p->children[ch-'a'])
                (p->children)[ch-'a'] = new TrieNode();
            p = p->children[ch-'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = Find(word);
        return p && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return Find(prefix);
    }
private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode *> children;
        TrieNode() : is_word(false), children(26, nullptr) {}
        ~TrieNode() {
            for (auto child : children)
                if (child)
                    delete child;
        }
    };
    unique_ptr<TrieNode> root;
    const TrieNode *Find(const string &s) {
        auto p = root.get();
        for (char ch : s) {
            p = p->children[ch-'a'];
            if (p == nullptr)
                break;
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
