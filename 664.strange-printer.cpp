/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (37.08%)
 * Total Accepted:    9.7K
 * Total Submissions: 26K
 * Testcase Example:  '"aaabbb"'
 *
 * 
 * There is a strange printer with the following two special requirements:
 * 
 * 
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 * 
 * 
 * 
 * 
 * 
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 * 
 * 
 * Example 1:
 * 
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 * 
 * 
 * 
 * Hint: Length of the given string will not exceed 100.
 */
class Solution {
public:
    int strangePrinter(string s) {
        int len = 0;
        cout << s << endl;
        for (int i = 0; i < s.length(); ++i) {
            s[len++] = s[i];
            while (i + 1 < s.length() && s[i+1] == s[i])
                ++i;
        }
        s.resize(len);
        cout << s << endl;
        m_ = vector<vector<int>>(len, vector<int>(len, 0));
        return print(s, 0, len - 1);
    }
private:
    vector<vector<int>> m_;
    int print(const string &s, int i, int j) {
        if (i > j)
            return 0;
        if (m_[i][j])
            return m_[i][j];
        m_[i][j] = print(s, i, j - 1) + 1;
        for (int k = i; k < j; ++k)
            if(s[k] == s[j])
                m_[i][j] = min(m_[i][j], print(s, i, k) + print(s, k + 1, j - 1));
        return m_[i][j];
    }
};
