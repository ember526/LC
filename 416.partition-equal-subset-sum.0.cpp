/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (40.96%)
 * Total Accepted:    97K
 * Total Submissions: 235.7K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        for (const int num : nums) {
            for (int i = sum; i >= 0; --i) {
                if (dp[i])
                    dp[i+num] = true;
            }
            if (dp[sum/2])
                return true;
        }
        return false;
    }
};
