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
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
    }
private:
    void permute(vector<int> nums, int round, vector<vector<int>> &result) {
        if (round == nums.size() - 1) {
            result.push_back(nums);
        }
        else {
            for (int i = round; i < nums.size(); ++i) {
                swap(nums[round], nums[i]);
                permute(nums, round + 1, result);
            }
        }
    }
};
