/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (42.29%)
 * Total Accepted:    234.8K
 * Total Submissions: 552K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty())        
            return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> cur;
        dfs(candidates, target, 0, 0, cur, result);
        return result;
    }
private:
    void dfs(const vector<int>& nums,
             int target,
             int start, int sum, vector<int>&cur, vector<vector<int>>& result) {
        if (sum > target)
            return;
        if (sum == target) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, target , i + 1, sum + nums[i], cur, result);
            cur.pop_back();
        }
        return;
    }
};
