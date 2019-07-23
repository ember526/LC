/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (38.91%)
 * Total Accepted:    50K
 * Total Submissions: 128.3K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
class Solution {
    int longestSubstring(string &s, int k, int start, int end) {
        if (start >= end)
            return 0;

        vector<int> counts(26, 0);
        for (int i = start; i < end; ++i)
            ++counts[s[i]-'a'];

        int i = start, maxlen = 0;
        while (i < end) {
            while (i < end && counts[s[i]-'a'] < k)
                ++i;
            if (i == end)
                break;
            int upper = i + 1;
            while (upper < end && counts[s[upper]-'a'] >= k)
                ++upper;
            if (i == start && upper == end)
                return upper - i;

            maxlen = max(maxlen, longestSubstring(s, k, i, upper));
            i = upper;
        }
        return maxlen;
    }
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.length());        
    }
};
