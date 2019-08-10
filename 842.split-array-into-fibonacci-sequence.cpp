/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 *
 * https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
 *
 * algorithms
 * Medium (34.97%)
 * Total Accepted:    12K
 * Total Submissions: 34.1K
 * Testcase Example:  '"123456579"'
 *
 * Given a string S of digits, such as S = "123456579", we can split it into a
 * Fibonacci-like sequence [123, 456, 579].
 * 
 * Formally, a Fibonacci-like sequence is a list F of non-negative integers
 * such that:
 * 
 * 
 * 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer
 * type);
 * F.length >= 3;
 * and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 * 
 * 
 * Also, note that when splitting the string into pieces, each piece must not
 * have extra leading zeroes, except if the piece is the number 0 itself.
 * 
 * Return any Fibonacci-like sequence split from S, or return [] if it cannot
 * be done.
 * 
 * Example 1:
 * 
 * 
 * Input: "123456579"
 * Output: [123,456,579]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "11235813"
 * Output: [1,1,2,3,5,8,13]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "112358130"
 * Output: []
 * Explanation: The task is impossible.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "0123"
 * Output: []
 * Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not
 * valid.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "1101111"
 * Output: [110, 1, 111]
 * Explanation: The output [11, 0, 11, 11] would also be accepted.
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= S.length <= 200
 * S contains only digits.
 * 
 * 
 */
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        split(S, 0, result);
        return result;
    }
private:
    bool split(const string &S, int start, vector<int> &result) {
        if (start == S.length())
            return result.size() > 2 ? true : false;
        for (int i = start; i < S.length(); ++i) {
            string sub = S.substr(start, i - start + 1);
            if (sub.length() > 10 || stol(sub) > numeric_limits<int>::max())
                continue;
            if (i > start && S[start] == '0')
                break;
            int num = stoi(sub);
            
            if ((result.size() < 2) || ((long)num == (long)result.back() + result[result.size() - 2])){
                result.push_back(num);
                if (split(S, i + 1, result))
                    return true;
                result.pop_back();
            }
        }
        return false;
    }
};
