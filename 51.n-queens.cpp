/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (40.00%)
 * Total Accepted:    151.2K
 * Total Submissions: 373K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        dia = vector<bool>(n * 2 - 1, false);
        ant = vector<bool>(n * 2 - 1, false);
        vector<vector<string>> result;
        dfs(board, n, result, 0);
        return result;
    }
private:
    vector<string> board;
    vector<bool> col, dia, ant;
    void dfs(vector<string> &board, int n, vector<vector<string>> & result, int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            int diaI = i + row, antI = i - row + n - 1;
            if (col[i] || dia[diaI] || ant[antI])
                continue;
            board[row][i] = 'Q';
            col[i] = dia[diaI] = ant[antI] = true;
            dfs(board, n, result, row + 1);
            board[row][i] = '.';
            col[i] = dia[diaI] = ant[antI] = false;
        }
        return;
    }
};
