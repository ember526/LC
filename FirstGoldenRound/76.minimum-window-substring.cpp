/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (31.22%)
 * Total Accepted:    252K
 * Total Submissions: 804.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty())
            return "";
        vector<int> counts(128, 0);
        for (char ch : t)
            ++counts[ch];

        int minLen = numeric_limits<int>::max(), minStart = -1,
            l = 0, r = 0,
            tChars = t.length();

        while (r < s.length()) {
            if (--counts[s[r++]] >= 0)
                --tChars;
            while (tChars == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    minStart = l;
                }
                if (++counts[s[l++]] > 0)
                    ++tChars;
            }
        }

        return minLen == numeric_limits<int>::max() ? "" : s.substr(minStart, minLen);
    }
};
