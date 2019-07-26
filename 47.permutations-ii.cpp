/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (41.10%)
 * Total Accepted:    257.2K
 * Total Submissions: 622.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())        
            return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, result);
        return result;
    }
private:
    void dfs(vector<int> nums, int swapi, vector<vector<int>>& result) {
        if (swapi == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = swapi; i < nums.size(); ++i) {  
            if (swapi != i && nums[swapi] == nums[i])
                continue;
            swap(nums[swapi], nums[i]);
            dfs(nums, swapi + 1, result);
        }
        return;
    }
};
