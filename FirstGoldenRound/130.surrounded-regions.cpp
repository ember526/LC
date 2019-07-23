/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (23.24%)
 * Total Accepted:    151K
 * Total Submissions: 649K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
    void infect(vector<vector<char>>& board, pair<int, int> pos) {
        queue<pair<int, int>> q;
        q.push(pos);
        int m = board.size(), n = board[0].size();
        while (q.empty() == false) {
            auto e = q.front();
            q.pop();
            int i = e.first, j = e.second;
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
                board[i][j] = '#';
                q.push(make_pair(i + 1, j));
                q.push(make_pair(i - 1, j));
                q.push(make_pair(i, j + 1));
                q.push(make_pair(i, j - 1));
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
        if (m < 2 || n < 2)    
            return;
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O')
                infect(board, make_pair(0, i));
            if (board[m-1][i] == 'O')
                infect(board, make_pair(m-1, i));
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                infect(board, make_pair(i, 0));
            if (board[i][n-1] == 'O')
                infect(board, make_pair(i, n-1));
        }
        for (auto &row : board)
            for (char &e : row) {
                if (e == 'O')
                    e = 'X';
                else if (e == '#')
                    e = 'O';
            }
        return;
    }
};
