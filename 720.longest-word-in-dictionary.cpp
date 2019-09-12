/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (45.43%)
 * Total Accepted:    41.4K
 * Total Submissions: 90.5K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given a list of strings words representing an English Dictionary, find the
 * longest word in words that can be built one character at a time by other
 * words in words.  If there is more than one possible answer, return the
 * longest word with the smallest lexicographical order.  If there is no
 * answer, return the empty string.
 * 
 * Example 1:
 * 
 * Input: 
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation: 
 * The word "world" can be built one character at a time by "w", "wo", "wor",
 * and "worl".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation: 
 * Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 * 
 * 
 * 
 * Note:
 * All the strings in the input will only contain lowercase letters.
 * The length of words will be in the range [1, 1000].
 * The length of words[i] will be in the range [1, 30].
 * 
 */
class Trie {
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

public:
    string result;
    Trie() : root(new TrieNode()) {}

    void insert(const string &word) {
        auto p = root.get();
        for (char ch : word) {
            if (p->children[ch-'a'] == nullptr)
                p->children[ch-'a'] = new TrieNode();
            p = p->children[ch-'a'];
        }
        p->is_word = true;
    }

    void search(TrieNode *p, string &cur) {
        p = p ? p : root.get();
        for (int i = 0; i < 26; ++i) {
            auto child = p->children[i];
            if (child == nullptr)
                continue;
            if (child->is_word) {
                cur.push_back('a' + i);
                if (cur.length() > result.length())
                    result = cur;
                search(child, cur);
                cur.pop_back();
            }
        }
        return;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tree;
        for (const string &s : words)
            tree.insert(s);
        string cur;
        tree.search(NULL, cur);
        return tree.result;
    }
};
