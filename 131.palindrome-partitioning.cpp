/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (41.52%)
 * Total Accepted:    170.1K
 * Total Submissions: 409.3K
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
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {};
        vector<string>cur;
        vector<vector<string>> result;
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
        for (int len = 1; len + start <= s.length(); ++len)
            if (isPalindrome(s, start, start + len - 1)) {
                cur.push_back(s.substr(start, len));
                partition(s, start + len, cur, result);
                cur.pop_back();
            }
        return;
    }

    bool isPalindrome(const string &s, int l, int r) {
        if (l >= r)
            return true;
        if (m_[l][r] != -1)
            return m_[l][r];
        if (s[l] == s[r])
            return m_[l][r] = isPalindrome(s, l + 1, r - 1);
        return m_[l][r] = 0;
    }
};
