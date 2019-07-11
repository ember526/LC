/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.49%)
 * Total Accepted:    588.7K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int head = 0, tail = 0, maxlen = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            int lefti = i, righti = i, curlen = 0;

            while (righti + 1 < length && s[righti+1] == s[righti]) 
                ++righti;
            i = righti;
            curlen = righti - lefti + 1;
            if (curlen > maxlen) {
                maxlen = curlen;
                head = lefti;
                tail = righti;
            }
            while (--lefti >= 0 && ++righti < length && s[lefti] == s[righti]) {
                curlen += 2;
                if (curlen > maxlen) {
                    head = lefti;
                    tail = righti;
                    maxlen = curlen;
                }
            }
        }
        return string(s.begin() + head, s.begin() + tail + 1);
        //return s.substr(head, maxlen);
    }
};
