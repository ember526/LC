/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (33.55%)
 * Likes:    839
 * Dislikes: 119
 * Total Accepted:    79.5K
 * Total Submissions: 234.7K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 * 
 * Example 1:
 * 
 * 
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"] 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 * 
 * Example 3:
 * 
 * 
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 * 
 * Example 4:
 * 
 * 
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: num = "3456237490", target = 9191
 * Output: []
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty())
            return {};
        string prefix = "";
        prefix += num[0];
        int val = num[0] - '0';
        vector<string> result;
        recur(num, 1, prefix, val, val, val, target, result);
        return result;
    }
private:
    void recur(const string &num, int idx, string &prefix, long value, long operand, long last, long target, vector<string> &result) {
        if (idx == num.length()) {
            if (value == target)
                result.push_back(prefix);
            return;
        }
        char ch = num[idx];
        long digit = ch - '0';
        // Addition
        prefix += '+';
        prefix += ch;
        recur(num, idx + 1, prefix, value + digit, digit, digit, target, result);
        prefix.pop_back();
        prefix.pop_back();
        // Subtraction
        prefix += '-';
        prefix += ch;
        recur(num, idx + 1, prefix, value - digit, digit, -digit, target, result);
        prefix.pop_back();
        prefix.pop_back();
        // Multi
        prefix += '*';
        prefix += ch;
        recur(num, idx + 1, prefix, value - last + digit * last, digit, digit * last, target, result);
        prefix.pop_back();
        prefix.pop_back();
        // Cat
        if (operand != 0) {
            prefix += ch;
            long newValue = last * 10 + digit * (last / operand);
            recur(num, idx + 1, prefix, value - last + newValue, operand * 10 + digit, newValue, target, result);
            prefix.pop_back();
        }
        return;
    }
};
// @lc code=end
