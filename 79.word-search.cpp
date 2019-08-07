/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (31.58%)
 * Total Accepted:    296.8K
 * Total Submissions: 937.7K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())        
            return true;
        if (board.empty() || board[0].empty())
            return false;
        dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfsSeek(board, word, i, j, 0))
                    return true;
        return false;
    }
private:
    vector<vector<int>> dirs;
    bool dfsSeek(vector<vector<char>> &board, const string &word,
                    int r, int c, int p) {
        cout << word[p];
        if (p == word.length())
            return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
                word[p] != board[r][c])
            return false;
        char tmp = board[r][c];
        board[r][c] = '\0';
        bool result = false;
        for (auto &dir : dirs) {
            result = dfsSeek(board, word, r + dir[0], c + dir[1], p + 1);
            if (result)
                break;
        }
        board[r][c] = tmp;
        return result;
    }
};
