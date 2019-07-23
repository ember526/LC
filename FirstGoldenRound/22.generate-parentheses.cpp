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
void generate (vector<string> &result, string cur, int open, int close, int max) {
    if (close == max) {
        result.push_back(cur);
        return;
    }
    if (open < max)
        generate(result, cur + "(", open + 1, close, max);
    if (open > close)
        generate(result, cur + ")", open, close + 1, max);
    return;
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur = "";
        generate(result, cur, 0, 0, n);
        return result;
    }
};
