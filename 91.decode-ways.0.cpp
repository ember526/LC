/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.51%)
 * Total Accepted:    271.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
bool isValid(char a, char b) {
    if (a == '1' || (a == '2' && b < '7'))
        return true;
    return false;
}

bool isValid(char a) {
    return a != '0';
}
public:
    int numDecodings(string s) {
        if (isValid(s[0]) == false)            
            return 0;
        if (s.length() == 1)
            return 1;
        int one = 1, two = 1;
        for (int i = 1; i < s.length(); ++i) {
            int cur = 0;
            if (isValid(s[i]) == false && isValid(s[i-1], s[i]) == false)
                return 0;
            if (isValid(s[i]) == true)
                cur = one;
            if (isValid(s[i-1], s[i]))
                cur += two;
            two = one;
            one = cur;
        }
        return one;
    }
};
