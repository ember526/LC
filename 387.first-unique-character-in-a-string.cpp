/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.08%)
 * Total Accepted:    280.2K
 * Total Submissions: 557.8K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> A(26, 0);
       for (char ch : s) 
            ++A[ch - 'a'];    
       for (int i = 0; i < s.size(); ++i) 
           if (A[s[i]-'a'] == 1)
               return i;
       return -1;
    }
};
