/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (32.45%)
 * Likes:    824
 * Dislikes: 351
 * Total Accepted:    155.9K
 * Total Submissions: 477.1K
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

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        partition(s, 0, result, 4);
        return result;
    }
private:
    inline bool validSub(const string &s, int start, int length) {
        string sub = s.substr(start, length);
        if (stoi(sub) > 255 || (length > 1 && s[start] == '0'))
            return false;
        return true;
    }

    void partition(string s, int pos, vector<string> &result, int k) {
        if (s.length() - pos > k * 3 || s.length() - pos < k)
            return;
        if (k == 1) {
           if (validSub(s, pos, s.length() - pos))
                result.push_back(s);
            return;
        }
        for (int i = pos; i < s.length(); ++i) {
            if (!validSub(s, pos, i - pos + 1))
                break;
            string tmp = s;
            tmp.insert(i + 1, 1, '.');
            partition(tmp, i + 2, result, k - 1);
        }
        return;
    }
};
// @lc code=end
