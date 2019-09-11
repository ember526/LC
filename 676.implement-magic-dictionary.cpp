/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (52.02%)
 * Total Accepted:    28.4K
 * Total Submissions: 54.6K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * 
 * Implement a magic directory with buildDict, and search methods.
 * 
 * 
 * 
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 * 
 * 
 * 
 * For the method search, you'll be given a word, and judge whether if you
 * modify exactly one character into another character in this word, the
 * modified word is in the dictionary you just built.
 * 
 * 
 * Example 1:
 * 
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that all the inputs are consist of lowercase letters a-z.
 * For contest purpose, the test data is rather small by now. You could think
 * about highly efficient algorithm after the contest.
 * Please remember to RESET your class variables declared in class
 * MagicDictionary, as static/class variables are persisted across multiple
 * test cases. Please see here for more details.
 * 
 * 
 */
class Trie {
public:
    Trie() : root(new TrieNode()) {}
    void Insert(const string &word) {
        auto p = root.get();
        for (char ch : word) {
            if (p->children[ch-'a'] == nullptr)
                p->children[ch-'a'] = new TrieNode();
            p = p->children[ch-'a'];
        }
        p->is_word = true;
    }

    bool FindWord(const string &word) {
        auto p = Find(word);
        return p && p->is_word;
    }
private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode *> children;
        TrieNode() : is_word(false), children(26, nullptr) {}
    };
    unique_ptr<TrieNode> root;

    TrieNode *Find(const string &s) {
        auto p = root.get();
        for (char ch : s) {
            p = p->children[ch-'a'];
            if (p == nullptr)
                break;
        }
        return p;
    }
};
class MagicDictionary {
    Trie *tree;
public:
    /** Initialize your data structure here. */
    MagicDictionary() : tree(new Trie()) {}
    ~MagicDictionary() {
        tree->~Trie();
    }
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string &s : dict)
            tree->Insert(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
       for (int i = 0; i < word.length(); ++i) {
           const char ori = word[i];
           for (char ch = 'a'; ch <= 'z'; ++ch) {
               if (ch == ori)
                   continue;
               word[i] = ch;
               if (tree->FindWord(word))
                   return true;
           }
           word[i] = ori;
       }
       return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
