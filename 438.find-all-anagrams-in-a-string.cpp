/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (38.44%)
 * Likes:    1925
 * Dislikes: 148
 * Total Accepted:    155.7K
 * Total Submissions: 399.2K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> sstats(26, 0), pstats(26, 0);
        if (s.length() < p.length())
            return result;
        for (int i = 0; i < p.length(); ++i) {
            ++sstats[s[i]-'a'];
            ++pstats[p[i]-'a'];
        }
        if (sstats == pstats)
            result.push_back(0);
        for (int i = p.length(); i < s.length(); ++i) {
            ++sstats[s[i]-'a'];
            --sstats[s[i-p.length()]-'a'];
            if (sstats == pstats)
                result.push_back(i - p.length() + 1);
        }       
        return result;
    }
};
// @lc code=end
