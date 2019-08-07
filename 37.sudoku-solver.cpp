/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (37.64%)
 * Total Accepted:    138.4K
 * Total Submissions: 363.6K
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
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows_ = vector<vector<bool>>(9, vector<bool>(10, false));
        cols_ = vector<vector<bool>>(9, vector<bool>(10, false));
        boxes_ = vector<vector<bool>>(9, vector<bool>(10, false));
        
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                const char ch = board[i][j];
                if (ch == '.') 
                    continue;
                int n = ch - '0';
                rows_[i][n] = cols_[j][n] = boxes_[i/3*3+j/3][n] = true;
            }

        fill(board, 0, 0);
    }
private:
    vector<vector<bool>> rows_, cols_, boxes_;

    bool fill (vector<vector<char>> &board, int x, int y) {
        if (y == 9)
            return true;

        int nx = (x + 1) % 9, ny = (nx == 0) ? y + 1 : y;
        if (board[y][x] != '.')
            return fill(board, nx, ny);

        for (int i = 1; i <= 9; ++i) {
            int bidx = y /3 * 3 + x / 3;
            if (rows_[y][i] || cols_[x][i] || boxes_[bidx][i])
                continue;
            //attempt
            board[y][x] = i + '0';
            rows_[y][i] = cols_[x][i] = boxes_[bidx][i] = true;
            if (fill(board, nx, ny))
                return true;
            board[y][x] = '.';
            rows_[y][i] = cols_[x][i] = boxes_[bidx][i] = false;
        }
        return false;
    }
};
