/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (29.54%)
 * Total Accepted:    221.8K
 * Total Submissions: 749.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int cmax = result, cmin = result;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(cmax, cmin);
            cmax = max(nums[i], nums[i]*cmax);
            cmin = min(nums[i], nums[i]*cmin);
            result = max(cmax, result);
        }
        return result;
    }
};
