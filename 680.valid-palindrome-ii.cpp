/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (34.90%)
 * Likes:    973
 * Dislikes: 67
 * Total Accepted:    100.9K
 * Total Submissions: 286.6K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return secondChance(s, l, r - 1) || secondChance(s, l + 1, r);
            ++l;
            --r;
        }
        return true;
    }
private:
    bool secondChance(const string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};
// @lc code=end
