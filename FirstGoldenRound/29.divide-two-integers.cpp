/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Total Accepted:    203.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        //overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long dvd = labs(dividend), dvs = labs(divisor);
        if (dvd < dvs)
            return 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long long ans = 0;

        long long tmp = dvs;
        int m = 1;
        while (tmp<<1 <= dvd) {
            tmp <<= 1;
            m <<= 1;
        }
        dvd -= tmp;
        ans += m;
        while (dvd - dvs >= 0) {
            dvd -= dvs;
            ++ans;
        }
        return sign > 0 ? ans : -ans;
    }
};
