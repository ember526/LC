/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.23%)
 * Total Accepted:    579.2K
 * Total Submissions: 2.4M
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
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        if(nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            int target = -nums[i];
            int front = i + 1, end = nums.size() - 1;
            while (front < end) {
                if (nums[front] + nums[end] == target) {
                    result.push_back({nums[i], nums[front], nums[end]});
                    ++front;
                    --end;
                    while (front<end && nums[front]==nums[front-1]) ++front;
                    while (front<end && nums[end]  ==nums[end+1]) --end;  
                }
                else if (nums[front] + nums[end] < target)
                    ++front;
                else if (nums[front] + nums[end] > target)
                    --end;
            }
            while (i + 1 < nums.size() &&  nums[i+1]==nums[i])
                ++i;
        }

        return result;
    }
};
