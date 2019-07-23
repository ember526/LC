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
            return false;
       m = board.size();
       n = board[0].size();
       for (int i = 0; i < m; ++i)
           for (int j = 0; j < n; ++j) {
               if (trace(board, word, 0, i, j))
                   return true;
           }
       return false;
    }
private:
    int m, n;
    bool trace(vector<vector<char>> &board, string &word, int pos, int i, int j) {
        if (pos == word.length())
            return true;
        if (i < 0 || i >= m)
            return false;
        if (j < 0 || j >= n)
            return false;
        if (word[pos] != board[i][j])
            return false;
        char ch = board[i][j];
        board[i][j] = 0;
        bool found = trace(board, word, pos + 1, i + 1, j) ||
                    trace(board, word, pos + 1, i - 1, j) ||
                    trace(board, word, pos + 1, i, j + 1) ||
                    trace(board, word, pos + 1, i, j - 1);
        board[i][j] = ch;
        return found;
    }
};
