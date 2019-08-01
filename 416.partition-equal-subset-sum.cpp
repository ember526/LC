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
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        sum >>= 1;
        vector<int> m_(sum + 1, -1);
        m_[0] = 1;
        int r = dp(nums, m_, sum);
        for (auto e : m_)
            cout << e << " ";
        return r ;//dp(nums, m_, sum);
    }
private:
    bool dp(vector<int> &nums, vector<int> &m_, int sum) {
        if (sum < 0)
            return false;
        if (m_[sum] != -1)
            return m_[sum];
        for (int &e : nums) {
            if (e < 0)
                continue;
            int tmp = e;
            e = -1;
            if (dp(nums, m_, sum - tmp)) {
                m_[sum] = 1;
                return true;
            }
            e = tmp;
        }
        m_[sum] = 0;
        return false;
    }
};
