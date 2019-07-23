/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (40.15%)
 * Total Accepted:    217.1K
 * Total Submissions: 540.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();        
        int logRow = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) {
                    logRow = i;
                    break;
                }
            if (logRow > -1)
                break;
        }
        if (logRow == -1)
            return;

        for (int i = logRow + 1; i < m; ++i) {
            bool hasZero = false;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[logRow][j] = 0;
                    hasZero = true;
                }
            }
            if (hasZero)
                for (int &e : matrix[i])
                    e = 0;
        }

        for (int i = 0; i < n; ++i) {
            if (matrix[logRow][i] == 0)
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
        }

        for (int &e : matrix[logRow])
            e = 0;
        return;
    }
};
