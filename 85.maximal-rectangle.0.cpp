/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (33.77%)
 * Total Accepted:    129.6K
 * Total Submissions: 380K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxarea = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j ? dp[i][j-1] + 1 : 1;
                    int width = dp[i][j];
                    for (int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width * (i - k + 1));
                    }
                }
            }
        return maxarea;
    }
};
