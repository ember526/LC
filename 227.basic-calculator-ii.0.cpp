/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (34.52%)
 * Likes:    905
 * Dislikes: 161
 * Total Accepted:    134.4K
 * Total Submissions: 385.5K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> adders;
        int num = 0, result = 0;
        char op = '+';
        istringstream iss(s);
        auto bondTop = [&](function<int(int, int)> op) {
            int top = adders.top();
            adders.pop();
            adders.push(op(top, num));
        };
        while (iss >> num) {
            switch (op) {
                case '+': adders.push(num); break;
                case '-': adders.push(-num); break;
                case '*': bondTop(multiplies<int>()); break;
                case '/': bondTop(divides<int>()); break;
            }
            iss >> op;
        }

        while (adders.empty() == false) {
            result += adders.top();
            adders.pop();
        }

        return result;
    }
};
// @lc code=end
