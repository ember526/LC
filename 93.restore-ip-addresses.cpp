/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (31.83%)
 * Total Accepted:    147.8K
 * Total Submissions: 460.3K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4)
            return {};
        vector<string> result;
        partition(s, 3, 0, 1, result);
        return result;
    }
private:
    void partition(string s, int k, int start, int len, vector<string> &result) {
        if (k == 0) {
            string remain = s.substr(start);
            if (remain.length() < 4 && stoi(remain) <= 255 && (remain.length() == 1 || remain[0] != '0'))
                result.push_back(s);
            return;
        }
        for (int i = start + len - 1; i < s.length() - k; ++i) {
            const string sub = s.substr(start, i - start + 1);
            if (stoi(sub) > 255)
                break;
            string tmp = s;
            tmp.insert(i + 1, ".");
            partition(tmp, k - 1, i + 2, 1, result);
            if (s[start] == '0')
                break;
        }
        return;
    }
};
