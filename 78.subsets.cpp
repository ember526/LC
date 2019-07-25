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
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        vector<int> cur;
        dfs(nums, 0, cur, result);
        return result;
    }
private:
    void dfs(const vector<int>& nums,
             int start, vector<int>& cur, vector<vector<int>>& result) {
        result.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, result);
            cur.pop_back();
        }
        return;
    }
};
