/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (54.94%)
 * Total Accepted:    22.6K
 * Total Submissions: 40.9K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for (int i = 1; i <= s1.length(); ++i)
            for (int j = 1; j <= s2.length(); ++j) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                int neighbor = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], neighbor);
            }
        int sum1 = 0, sum2 = 0;
        for (char ch : s1)
            sum1 += ch;
        for (char ch : s2)
            sum2 += ch;
        return sum1 - dp[s1.length()][s2.length()] + sum2 - dp[s1.length()][s2.length()];
    }
};
