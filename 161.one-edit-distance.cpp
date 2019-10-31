/*
 * @lc app=leetcode id=161 lang=cpp
 *
 * [161] One Edit Distance
 *
 * https://leetcode.com/problems/one-edit-distance/description/
 *
 * algorithms
 * Medium (31.95%)
 * Likes:    473
 * Dislikes: 93
 * Total Accepted:    89.8K
 * Total Submissions: 280.2K
 * Testcase Example:  '"ab"\n"acb"'
 *
 * Given two strings s and t, determine if they are both one edit distance
 * apart.
 * 
 * Note: 
 * 
 * There are 3 possiblities to satisify one edit distance apart:
 * 
 * 
 * Insert a character into s to get t
 * Delete a character from s to get t
 * Replace a character of s to get t
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ab", t = "acb"
 * Output: true
 * Explanation: We can insert 'c' into s to get t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cab", t = "ad"
 * Output: false
 * Explanation: We cannot get t from s by only one step.
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1203", t = "1213"
 * Output: true
 * Explanation: We can replace '0' with '1' to get t.
 * 
 */

// @lc code=start
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int dis = s.length() - t.length();
        if (dis > 1 || dis < -1)
            return false;
        for (int i = 0, j = 0; i < s.length() && j < t.length(); ++i, ++j)
            if (s[i] != t[j])
                return (dis == 1  && secondChance(s, i + 1, t, j))
                    || (dis == -1 && secondChance(s, i, t, j + 1))
                    || (dis == 0  &&secondChance(s, i + 1, t, j + 1));
        if (dis == 1 || dis == -1)
            return true;
        return false;
    }
private:
    bool secondChance(const string &s, int i, const string &t, int j) {
        while (i < s.length() && j < t.length())
            if (s[i++] != t[j++])
                return false;
        return true;
    }
  
};
// @lc code=end
