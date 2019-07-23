/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Hard (40.13%)
 * Total Accepted:    79.5K
 * Total Submissions: 197.5K
 * Testcase Example:  '"eceba"\n2'
 *
 * Given a string, find the length of the longest substring T that contains at
 * most k distinct characters.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: T is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: T is "aa" which its length is 2.
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty() || k == 0)
            return 0;
        unordered_map<char, int> m;
        int l = 0, r = 0, distinct = 0;
        int maxlen = 0;
        while (r < s.length()) {
            while (r < s.length() && distinct <= k) {
                char ch = s[r++];
                if (m[ch]++ == 0)
                    ++distinct;
            }
            maxlen = max(maxlen, distinct <= k ? r - l : r - l - 1);
            //cout << l << " " << r << " " << distinct << "/";
            while (distinct > k) {
                char ch = s[l++];
                if (m[ch]-- == 1)
                    --distinct;
            }
        }
        return maxlen;
    }
};
