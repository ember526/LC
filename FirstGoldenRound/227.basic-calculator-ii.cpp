/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (33.81%)
 * Total Accepted:    116.2K
 * Total Submissions: 343.1K
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
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int tmp, result = 0;
        char op = '+';
        istringstream in(s);
        while (in >> tmp) {
            if (op == '+')
                nums.push(tmp);
            else if (op == '-')
                nums.push(-tmp);
            else {
                int top = nums.top();
                nums.pop();
                tmp = op == '*' ? tmp * top : top / tmp;
                nums.push(tmp);
            }
            in >> op;
        }
        while (nums.empty() == false) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
