/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (57.62%)
 * Total Accepted:    51.4K
 * Total Submissions: 88.8K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 * 
 * 
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * Note:
 * 
 * 
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 * 
 * 
 */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S.empty())
            return {};
        vector<string> result;
        function<void(int)> dfs = [&](int pos) {
            result.push_back(S);
            if (pos == S.length())
                return;
            for (int i = pos; i < S.length(); ++i) {
                if (isdigit(S[i]))
                    continue;
                char ch = S[i];
                S[i] = islower(ch) ? toupper(ch) : tolower(ch);
                dfs(i + 1);
                S[i] = ch;
            }
            return;
        };
        dfs(0);
        return result;
    }
};
