/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.09%)
 * Total Accepted:    410K
 * Total Submissions: 973.6K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //DFS solution
        if (digits.empty())
            return {};
        vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string cur;
        dfs(digits, keys, 0, cur, result);
        return result;
    }
private:
    void dfs(const string& digits,
             const vector<string>& keys,
             int i, string &cur, vector<string> &result) { 
        if (i == digits.length()) {
            result.push_back(cur);
            return;
        }
        for (char letter : keys[digits[i] - '0']) {
            cur.push_back(letter);
            dfs(digits, keys, i + 1, cur, result);
            cur.pop_back();
        }
        return;
    }
};