/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    1160
 * Dislikes: 60
 * Total Accepted:    83.8K
 * Total Submissions: 161.4K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        ops['+'] = plus<int>();
        ops['-'] = minus<int>();
        ops['*'] = multiplies<int>();
        ops['/'] = divides<int>();
        return partition(input);
    }
private:
    unordered_map<string, vector<int>> m_;
    unordered_map<char, function<int(int, int)>> ops;
    const vector<int> &partition(const string &s) {
        if (m_.find(s) != m_.end())
            return m_[s];
        vector<int> result;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i]))
                continue;
            string left = s.substr(0, i),
                   right = s.substr(i + 1);
            auto &lvals = partition(left);
            auto &rvals = partition(right);
            auto &op = ops[s[i]];
            for (const int &a : lvals)
                for (const int &b : rvals)
                    result.push_back(op(a, b));
        }
        if (result.empty())
            result.push_back(stoi(s));
        m_[s].swap(result);
        return m_[s];
    }
};
// @lc code=end
