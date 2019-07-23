/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (29.15%)
 * Total Accepted:    119.8K
 * Total Submissions: 409.8K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */
class TrieNode {
public:
    array<TrieNode*, 26> next;
    string word;
    TrieNode() : word(""), next({0}) {};
    ~TrieNode() {
        for (auto p : next)
            delete p;
    }
};
class Solution {
private:
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode * p = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (p->next[index] == NULL)
                    p->next[index] = new TrieNode();
                p = p->next[index];
            }
            p->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, vector<string> &result, TrieNode *node) {
        char ch = board[i][j];
        if (ch == '#' || node->next[ch-'a'] == NULL)
            return;
        node = node->next[ch-'a'];
        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, result, node);
        if (i < board.size() - 1) dfs(board, i + 1, j, result, node);
        if (j > 0) dfs(board, i, j - 1, result, node);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, result, node);
        board[i][j] = ch;
        return;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode *root = buildTrie(words);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, result, root);
        return result;
    }
};
