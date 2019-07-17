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
class TrieNode {
private:
    char ch;
    bool isEnd;
public:
    vector<TrieNode *> children;
    TrieNode(char _ch = '#') : ch(_ch), isEnd(false) {} 
    void setEnd() {
        isEnd = true;
    }
    bool canEnd() {
        return isEnd;
    }
    TrieNode *getChild (char _ch) {
        for (auto child : children)
            if (_ch == child->ch)
                return child;
        return nullptr;
    }
    ~TrieNode() {
        for (auto child :children)
            delete child;
    }
};
class Trie {
    TrieNode * const root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) { }
    ~Trie () {
        delete root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
            return;
        TrieNode *cur = root;
        for (char ch : word) {
            TrieNode *child = cur->getChild(ch);
            if (child)
                cur = child;
            else {
                child = new TrieNode(ch);
                cur->children.push_back(child);
                cur = child;
            }
        }
        cur->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (char ch : word) {
            TrieNode *child = cur->getChild(ch);
            if (child == NULL)
                return false;
            cur = child;
        }
        return cur->canEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char ch : prefix) {
            TrieNode *child = cur->getChild(ch);
            if (child == NULL)
                return false;
            cur = child;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
