/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (50.46%)
 * Total Accepted:    78K
 * Total Submissions: 153.4K
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
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return partition(input);
    }
private:
    unordered_map<string, vector<int>> m_;
    const vector<int> &partition(const string &input) {
        if (m_.count(input))
            return m_[input];
        vector<int> result;
        //Break the input at operators
        for (int i = 0; i < input.length(); ++i) {
            char ch = input[i];
            if (isdigit(ch))
                continue;
            const string leftstr = input.substr(0, i), 
                        rightstr = input.substr(i + 1);
            const vector<int> &left = partition(leftstr);
            const vector<int> &right = partition(rightstr);

            function<int(int, int)> op;
            if (ch == '+')
                op = plus<int>();
            else if (ch == '-')
                op = minus<int>();
            else if (ch == '*')
                op = multiplies<int>();

            for (int l : left)
                for (int r : right)
                    result.push_back(op(l, r));
        }

        if (result.empty())
            result.push_back(stoi(input));
        m_[input].swap(result);
        return m_[input];
    }
};
