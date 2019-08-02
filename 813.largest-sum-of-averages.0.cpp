/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (45.61%)
 * Total Accepted:    14.6K
 * Total Submissions: 31.8K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        const int n = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0));
        vector<double> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + A[i-1];
            dp[1][i] = sum[i] / i;
        }
        
        for (int k = 2; k <= K; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = k - 1; j < i; ++j)
                    dp[k][i] = max(dp[k][i], dp[k-1][j] + (sum[i] - sum[j]) / (i - j));
        return dp[K][n];
    }
};
