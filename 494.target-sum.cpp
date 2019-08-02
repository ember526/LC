/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.40%)
 * Total Accepted:    104.1K
 * Total Submissions: 228.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;
        if (S > sum || S < -sum)
            return 0;
        vector<int> dp(2*sum + 1, 0);
        dp[sum] = 1;
        for (const int e : nums) {
            vector<int> tmp(2*sum + 1, 0);
            for (int i = 0; i < 2*sum + 1; ++i) {
                if (dp[i] == 0)
                    continue;
                if (i - e >= 0)
                    tmp[i-e] += dp[i];
                if (i + e < 2 * sum + 1)
                    tmp[i+e] += dp[i];
            }
            dp.swap(tmp);
        }
        for (int i : dp)
            cout << i << " ";
        return dp[S + offset];
    }
};
