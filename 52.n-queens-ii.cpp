/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (52.58%)
 * Total Accepted:    105K
 * Total Submissions: 198K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        ant = vector<bool>(2 * n - 1, false);
        dia = vector<bool>(2 * n - 1, false);
        int result = 0;
        dfs(n, result, 0);
        return result;
    }
private:
    vector<bool> col, ant, dia;
    void dfs(const int n, int &result, int row) {
        if (row == n) {
            ++result;
            return;
        }
        for (int i = 0; i < n; ++i) {
            int antI = i - row + n - 1,
                diaI = i + row;
            if (col[i] || ant[antI] || dia[diaI])
                continue;
            col[i] = true;
            ant[antI] = true;
            dia[diaI] = true;
            dfs(n, result, row + 1);
            col[i] = false;
            ant[antI] = false;
            dia[diaI] = false;
        }
        return;
    }
};
