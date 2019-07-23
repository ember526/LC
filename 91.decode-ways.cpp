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
private:
    int numDecodings(string &s, int i) {
        if (s[i] == '0')
            return 0;
        switch (s.length() - i) {
            case 0:
                return 1;
            case 1:
                return 1 * numDecodings(s, i + 1);
            default:
                string tmp;
                int num = 0;
                tmp = tmp + s[i] + s[i+1];
                num = stoi(tmp);
                if (num > 26)
                    return s[i+1]=='0' ? 0 :numDecodings(s, i + 1);
                return
                    return numDecodings(s, i + 1) + numDecodings(s, i + 2);
        }
    }
public:
    int numDecodings(string s) {
        if (s[0] == 0)
            return 0;
        return numDecodings(s, 0);            
    }
};
