/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (55.29%)
 * Total Accepted:    393.5K
 * Total Submissions: 705.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        function<void(int)> recur = [&](int swapi) {
            if (swapi == nums.size() - 1) {
                result.push_back(nums);
                return;
            }
            for (int i = swapi; i < nums.size(); ++i) {
                swap(nums[swapi], nums[i]);
                recur(swapi + 1);
                swap(nums[swapi], nums[i]);
            }
        };
        recur(0);
        return result;
    }
};
