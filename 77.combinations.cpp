/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (48.38%)
 * Total Accepted:    213.7K
 * Total Submissions: 439.3K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (!n || !k || n < k)
            return {};
        vector<vector<int>> result;
        vector<int> cur;
        dfs(n, k, 1, result, cur);
        return result;
    }
private:
    void dfs(int n, int k,
             int start, vector<vector<int>>& result, vector<int>& cur) {
        if (cur.size() == k) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            dfs(n, k, i + 1, result, cur);
            cur.pop_back();
        }
        return;
    }
};
