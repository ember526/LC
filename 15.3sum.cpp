/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.78%)
 * Likes:    4745
 * Dislikes: 562
 * Total Accepted:    679.4K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r && nums[r] >= 0) {
                int lval = nums[l], rval = nums[r];
                if (lval + rval == target) {
                    result.push_back({nums[i], lval, rval});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }
                else if (lval + rval < target)
                    ++l;
                else
                    --r;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1])
                ++i;
        }
        return result;
    }
};
// @lc code=end
