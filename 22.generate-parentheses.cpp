/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (55.67%)
 * Total Accepted:    358K
 * Total Submissions: 642.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        dfs(n, 0, 0, result, cur);
        return result;
    }
private:
    void dfs(int n, int open, int close, vector<string>& result, string & cur) {
        if (close == n) {
            result.push_back(cur);
            return;
        }
        if (open == n) {
            cur += ')';
            dfs(n, open, close + 1, result, cur);
        }
        else if (close == open) {
            cur += '(';
            dfs(n, open + 1, close, result, cur);
        }
        else {
             cur += '(';
             dfs(n, open + 1, close, result, cur);
             cur.pop_back();
             cur += ')';
             dfs(n, open, close + 1, result, cur);
        }
        cur.pop_back();
    }
};
