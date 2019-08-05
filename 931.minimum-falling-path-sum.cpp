/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (59.05%)
 * Total Accepted:    21.7K
 * Total Submissions: 36.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a square array of integers A, we want the minimum sum of a falling
 * path through A.
 * 
 * A falling path starts at any element in the first row, and chooses one
 * element from each row.  The next row's choice must be in a column that is
 * different from the previous row's column by at most one.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 12
 * Explanation: 
 * The possible falling paths are:
 * 
 * 
 * 
 * [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 * [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 * [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 * 
 * 
 * The falling path with the smallest sum is [1,4,7], so the answer is 12.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length == A[0].length <= 100
 * -100 <= A[i][j] <= 100
 * 
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty())        
            return 0;
        int m = A.size(), n = A[0].size();
        if (n == 1) {
            int sum = 0;
            for (auto &row : A)
                sum += row[0];
            return sum;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> tmp(n, 0);
            tmp[0] = A[i][0] + min(dp[0], dp[1]);
            tmp[n-1] = A[i][n-1] + min(dp[n-1], dp[n-2]);
            for (int j = 1; j < n - 1; ++j) 
                tmp[j] = A[i][j] + min(dp[j-1], min(dp[j], dp[j+1]));
            dp.swap(tmp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
