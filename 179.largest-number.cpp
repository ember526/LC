/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (26.04%)
 * Total Accepted:    134.2K
 * Total Submissions: 514.7K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int a) { return a == 0; }))
            return "0";
        vector<string> arr;
        for (int e : nums)
            arr.push_back(to_string(e));
        sort(arr.begin(), arr.end(), [](string &a, string &b) { return a + b > b + a;} );
        return accumulate(arr.begin(), arr.end(), string(""));
    }
};
