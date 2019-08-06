/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (39.63%)
 * Total Accepted:    133.7K
 * Total Submissions: 336.3K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 * 
 * Example 1:
 * 
 * 
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ")("
 * Output: [""]
 * 
 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int l, r;
        countInvalid(s, l, r);
        dfs(s, 0, l, r, result);
        return result;
    }
private:
    void dfs(const string &s, int start, int l, int r, vector<string> &result) {
        if (l == 0 && r == 0 && isValid(s)) {
            result.push_back(s);
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (i != start && s[i] == s[i-1])
                continue;
            if (s[i] == '(' || s[i] == ')') {
                string cur = s;
                cur.erase(i, 1);
                if (l > 0 && s[i] == '(')
                    dfs(cur, i, l - 1, r, result);
                else if (r > 0 && s[i] == ')')
                    dfs(cur, i, l, r - 1, result);
            }
        }
        return;
    }
    void countInvalid(const string &s, int &l, int &r) {
        r = l = 0;
        for (const char ch : s) {
            if (ch == '(')
                ++l;
            else if (ch == ')') {
                if (l == 0)
                    ++r;
                else
                    --l;
            }
        }
    }
    
    bool isValid(const string &s) {
        int left = 0;
        for (const char ch : s) {
            if (ch == '(')
                ++left;
            if (ch == ')')
                --left;
            if (left < 0)
                return false;
        }
        return left == 0;
    }
};
