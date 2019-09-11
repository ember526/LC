/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (52.80%)
 * Total Accepted:    39K
 * Total Submissions: 73.5K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 * 
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 * 
 * You need to output the sentence after the replacement.
 * 
 * Example 1:
 * 
 * 
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input will only have lower-case letters.
 * 1 <= dict words number <= 1000
 * 1 <= sentence words number <= 1000
 * 1 <= root length <= 100
 * 1 <= sentence words length <= 1000
 * 
 * 
 * 
 * 
 */
class Trie {
public:
    Trie() : root(new TrieNode()) {}
    void Insert(string word) {
        auto p = root.get();
        for (char ch : word) {
            if (p->children[ch-'a'] == nullptr)
                p->children[ch-'a'] = new TrieNode();
            p = p->children[ch-'a'];
        }
        p->is_word = true;
    }

    int FindRoot(string word) {
        auto p = root.get();
        int len = 0;
        for (char ch : word) {
            p = p->children[ch-'a'];
            if (p == nullptr)
                break;
            ++len;
            if (p->is_word)
                return len;
        }
        return word.size();
    }
private:
    struct TrieNode {
        bool is_word;
        vector<TrieNode *> children;
        TrieNode() : is_word(nullptr), children(26, nullptr) {}
        ~TrieNode() {
            for (auto child : children)
                if (child)
                    delete child;
        }
    };
    unique_ptr<TrieNode> root;
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if (sentence.empty())
            return sentence;
        Trie tree;
        for (const string &s : dict)
            tree.Insert(s);
        istringstream iss(sentence);
        string result;
        string word;
        while (iss >> word)
            result += word.substr(0, tree.FindRoot(word)) + " ";
        result.pop_back();
        return result;
    }
};
