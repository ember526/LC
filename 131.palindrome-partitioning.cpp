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
    void grow(vector<vector<string>> &result, vector<string> &prefix, string s, int start) {
        if (start == s.size()) {
            result.push_back(prefix);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                prefix.push_back(s.substr(start, i - start + 1));
                grow(result, prefix, s, i + 1);
                prefix.pop_back();
            }
        }
        return;
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return {};
        vector<vector<string>>result;
        vector<string>prefix;
        grow(result, prefix, s, 0);
        return result;
    }
};
