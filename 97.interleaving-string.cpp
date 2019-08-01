/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (28.31%)
 * Total Accepted:    116.9K
 * Total Submissions: 410.5K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s1.length() && s1[i-1] == s3[i-1]; ++i)
            dp[i][0] = true;
        for (int j = 1; j <= s2.length() && s2[j-1] == s3[j-1]; ++j)
            dp[0][j] = true;
        for (int i = 1; i <= s1.length(); ++i)
            for (int j = 1; j <= s2.length(); ++j)
                dp[i][j] =  (s1[i-1] == s3[i+j-1] && dp[i-1][j])||
                                (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
        return dp[s1.length()][s2.length()];
    }
};
