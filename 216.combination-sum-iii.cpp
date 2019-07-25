/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (52.04%)
 * Total Accepted:    127.6K
 * Total Submissions: 244.4K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n <= 0)
            return {};
        vector<int> cur;
        vector<vector<int>> result;
        function<void(int)> dfs = [&](int sum) {
            if (sum == n && cur.size() == k) {
                result.push_back(cur);
                return;
            }
            for (int i = cur.empty() ? 1 : cur.back() + 1; i < 10; ++i) {
                if (n - sum < k - cur.size())
                    break;
                cur.push_back(i);
                dfs(sum + i);
                cur.pop_back();
            }
            return;
        };
        dfs(0);
        return result;
    }
};
