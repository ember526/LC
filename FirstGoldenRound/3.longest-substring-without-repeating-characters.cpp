/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.53%)
 * Total Accepted:    982.3K
 * Total Submissions: 3.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    // the question description does not say anything about case
    int lengthOfLongestSubstring(string s) {
        //cout <<"a"<< s << "a : " << s.length() << endl;
        int maxlen = 0, head = 0;
        vector<int> v(256, -1);
        for (int i = 0; i < s.length(); i++) {
            int &lastOccur = v[s[i]];
            if (lastOccur != -1) {
                if (i - head > maxlen)
                    maxlen = i - head;
                head = max(head, lastOccur + 1);
            }
            lastOccur = i;
            
        }
        return s.length() - head > maxlen ? s.length() - head : maxlen;
    }
};
