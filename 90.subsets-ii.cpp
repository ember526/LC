/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (42.87%)
 * Total Accepted:    212.7K
 * Total Submissions: 494.2K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())        
            return {};
        vector<vector<int>> result;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, cur, result);
        return result;
    }
private:
    void dfs(const vector<int>& nums,
             int start, vector<int>& cur, vector<vector<int>>& result) {
        result.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, result);
            cur.pop_back();
        }
        return;
    }
};
