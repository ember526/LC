/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.74%)
 * Total Accepted:    89.8K
 * Total Submissions: 205.1K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        m_ = vector<int>(target + 1, -1);
        m_[0] = 1;
        return dp(nums, target);
    }
private:
    int dp(vector<int> &nums, int target) {
        if (target < 0)
            return 0;
        if (m_[target] >= 0)
            return m_[target];
        int ans = 0;
        for (int e : nums)
            ans += dp(nums, target - e);
        return m_[target] = ans;
    }
    vector<int> m_;
};
