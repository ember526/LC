/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    1168
 * Dislikes: 48
 * Total Accepted:    185.4K
 * Total Submissions: 430.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {};
        vector<vector<string>> result;
        vector<string> cur;
        m_ = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        partition(s, 0, cur, result);
        return result;
    }
private:
    vector<vector<int>> m_;

    void partition(const string &s, int start, vector<string> &cur, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(cur);
            return;
        }
        for (int len = 1; len + start - 1 < s.length(); ++len) {
            if (isPalindrome(s, start, start + len - 1)) {
                cur.emplace_back(s.substr(start, len));
                partition(s, start + len, cur, result);
                cur.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(const string &s, int i, int j) {
        if (i >= j)
            return true;
        if (m_[i][j] != -1)
            return m_[i][j];
        if (s[i] == s[j]) 
            return m_[i][j] = isPalindrome(s, i + 1, j - 1);
        return m_[i][j] = 0;
    }
};
// @lc code=end
