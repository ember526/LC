/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.44%)
 * Likes:    3099
 * Dislikes: 72
 * Total Accepted:    270.8K
 * Total Submissions: 651.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> ends;
        for (int i =0; i < nums.size(); ++i) {
            auto iter = lower_bound(ends.begin(), ends.end(), nums[i]);
            if (iter == ends.end())
                ends.push_back(nums[i]);
            else
                *iter = nums[i];
        }
        return ends.size();
    }
};
// @lc code=end
