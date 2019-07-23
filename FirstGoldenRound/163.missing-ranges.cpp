/*
 * @lc app=leetcode id=163 lang=cpp
 *
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (23.33%)
 * Total Accepted:    57.8K
 * Total Submissions: 248K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * 
 * 
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 * 
 * 
 */
class Solution {
    string getRange(int start, int end) {
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.empty())
            return { getRange(lower, upper) };
        long long pre = (long long)lower - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if ((long long)nums[i] - 1 > pre)
                result.push_back(getRange(pre + 1, nums[i] - 1));
            pre = nums[i];
        }
        if (upper >= 1 + pre)
            result.push_back(getRange(pre + 1, upper));
        return result;
    }
};
