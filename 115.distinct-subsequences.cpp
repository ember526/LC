/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (35.33%)
 * Total Accepted:    110.6K
 * Total Submissions: 312K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(t.length() + 1, vector<long>(s.length() + 1, 0));
        fill(begin(dp[0]), end(dp[0]), 1);
        for (int i = 1; i <= t.length(); ++i)
            for (int j = 1; j <= s.length(); ++j) {
                if (t[i-1] == s[j-1])
                    dp[i][j] += dp[i-1][j-1];
                dp[i][j] += dp[i][j-1];
            }
        //for (auto &row : dp) {
        //    for (int e : row)
        //        cout << e << " ";
        //    cout << endl;
        //}
        return dp[t.length()][s.length()];
        //return accumulate(dp.back().begin(), dp.back().end(), 0);
    }
};
