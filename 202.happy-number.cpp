/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (45.70%)
 * Total Accepted:    243.8K
 * Total Submissions: 533.5K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (1) {
            slow = oneRound(slow);
            fast = oneRound(fast);
            fast = oneRound(fast);
            if (fast == 1)
                return true;
            if (slow == fast)
                return false;
        }
        return true;
    }
private:
    int oneRound(int n) {
        int result = 0;
        while (n) { 
            int digit = n % 10;
            n /= 10;
           result += digit * digit;
        }
        return result;
    }
};
