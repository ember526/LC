/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    186.6K
 * Total Submissions: 569.9K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
         while (l <= r) {
             int mid = l + (r - l) / 2;
             if (nums[mid] == target)
                 return true;
             if (nums[r] == nums[mid]) {
                 --r;
             }
             else if (nums[mid] > target) {
                 if (nums[mid] > nums[r]) {
                     if (nums[r] >= target)
                         l = mid + 1;
                     else
                         r = mid - 1;
                 }
                 else
                     r = mid - 1;
             }
             else {
                 if (nums[mid] > nums[r])
                     l = mid + 1;
                 else {
                     if (nums[r] >= target)
                         l = mid + 1;
                     else
                         r = mid - 1;
                 }
             }
         }
         return false;
    }
};
