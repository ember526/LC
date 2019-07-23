/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (31.63%)
 * Total Accepted:    385.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        if (x <= 5)
            return x / 2;
        int low = 1, high = x / 2;
        while (low < high) {
            long long mid = (low + high) / 2;
            long long lower = mid * mid;
            long long upper = (mid + 1) * (mid + 1);
            if (lower > x)
                high = mid;
            else if (lower <= x && upper > x)
                return mid;
            else
                low = mid + 1;
        }
        return 0;
    }
};
