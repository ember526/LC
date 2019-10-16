/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (30.08%)
 * Likes:    1466
 * Dislikes: 81
 * Total Accepted:    137.3K
 * Total Submissions: 451.2K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
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

// @lc code=start
class TrieNode {
    public:
        bool is_word;
        vector<TrieNode *>children;
        TrieNode() : is_word(false), children(26, nullptr) {}
        ~TrieNode() {
            for (auto &child : children)
                if (child)
                    delete child;
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = unique_ptr<TrieNode>(new TrieNode());
        TrieNode *p = root.get();
        for (const string &word : words)
            Insert(word);
        vector<string> result;
        string pre;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (p->children[board[i][j] - 'a'])
                    Dfs(board, i, j, p->children[board[i][j] - 'a'], result, pre);
        return result;
    }
private:
    unique_ptr<TrieNode> root;
    void Dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result, string &tmp) {
        char ch = board[i][j];
        board[i][j] = '#';
        tmp.push_back(ch);
        if (p->is_word) {
            p->is_word = false;
            result.emplace_back(tmp);
        }
        vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni < 0 || nj < 0 || ni >= board.size() || nj >= board[0].size())
               continue;
            if (board[ni][nj] == '#' || p->children[board[ni][nj] - 'a'] == NULL) {
                continue;
            }
            Dfs(board, ni, nj, p->children[board[ni][nj]-'a'], result, tmp);
        }
        tmp.pop_back();
        board[i][j] = ch;
    }
    
    void Insert(const string &word) {
        auto p = root.get();
        for(const char &ch : word) {
            auto &slot = p->children[ch - 'a'];
            if (slot == nullptr)
                slot = new TrieNode();
            p = slot;
        }
        p->is_word = true;
    }
};
// @lc code=end
