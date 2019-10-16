/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (38.78%)
 * Likes:    1128
 * Dislikes: 74
 * Total Accepted:    147.7K
 * Total Submissions: 377.9K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        col_ = vector<vector<bool>>(9, vector<bool>(9, false));
        row_ = vector<vector<bool>>(9, vector<bool>(9, false));
        box_ = vector<vector<bool>>(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    AddConstraint(board[i][j], i, j);
        Dfs(board, 0, 0);
        return;
    }
private:
    vector<vector<bool>> col_;
    vector<vector<bool>> row_;
    vector<vector<bool>> box_;
    bool Dfs(vector<vector<char>> &board, int y, int x) {
        if (y == 9)
            return true;
        char ch = board[y][x];
        int ny = x == 8 ? y + 1 : y, nx = (x + 1) % 9;
        if (ch != '.')
            return Dfs(board, ny, nx);

        for (char g = '1'; g <= '9' ; ++g) {
            if (!IsValid(g, y, x))
                continue;
            board[y][x] = g;
            AddConstraint(g, y, x);
            if (Dfs(board, ny, nx) == false) {
                board[y][x] = ch;
                DelConstraint(g, y, x);
            }
            else
                return true;
        }
        return false;
    }

    inline int GetBoxIndex(int y, int x) { return y / 3 * 3 + x / 3; }
    inline int IsValid(char ch, int y, int x) { 
        int i = ch - '1';
        if (col_[x][i] || row_[y][i] || box_[GetBoxIndex(y, x)][i])
            return false;
        return true;
    }
  
    void AddConstraint(char ch, int y, int x) {
        int i = ch - '1';
        col_[x][i] = true;
        row_[y][i] = true;
        box_[GetBoxIndex(y, x)][i] = true;
        return;
    }

    void DelConstraint(char ch, int y, int x) {
        int i = ch - '1';
        col_[x][i] = false;
        row_[y][i] = false;
        box_[GetBoxIndex(y, x)][i] = false;
        return;
    }

};
// @lc code=end
