/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (27.63%)
 * Total Accepted:    165.5K
 * Total Submissions: 597.4K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.length() + 1, vector<int>());
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((j == 0 || dp[j].empty() == false) && dict.find(s.substr(j, i - j)) != dict.end())
                    dp[i].push_back(j);
            }
        }
        
        function<vector<string>(int)> build = [&](int idx) {
            if (idx == 0) {
                return vector<string>({""});
            }
            vector<string> cur = {};
            for (int e : dp[idx]) {
                vector<string> tmp = build(e);
                for (string &prefix : tmp) {
                    prefix += s.substr(e, idx - e);
                    if (idx != s.length())
                        prefix += " ";
                }
                cur.insert(begin(cur), tmp.begin(), tmp.end());
            }
            return cur;
        };
        return build(s.length());
    }
};
