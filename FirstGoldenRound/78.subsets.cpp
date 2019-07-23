/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (53.47%)
 * Total Accepted:    382.2K
 * Total Submissions: 713K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> buffer;
        subsets(nums, 0, buffer, result);
        return result;
    }
private:
    void subsets(vector<int> &nums, int round, vector<int> &buf, vector<vector<int>> &result) {
       result.push_back(buf);
       for (int i = round; i < nums.size(); ++i) {
           buf.push_back(nums[i]);
           subsets(nums, i + 1, buf, result);
           buf.pop_back();
       }
    }
};
