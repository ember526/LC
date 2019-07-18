/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (42.39%)
 * Total Accepted:    193.2K
 * Total Submissions: 455K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
        int cnt = 1;
        vector<int> squares;
        vector<int> record(n, 0);
        queue<int> layer;

        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
            record[i * i - 1] =  1;
            layer.push(i * i);
        }
        if (record[n-1])
            return 1;

        while (layer.empty() == false) {
            ++cnt;
            int size = layer.size();
            for (int i = 0; i < size; ++i) {
                int front = layer.front();
                layer.pop();

                for (int square : squares) {
                    int sum = square + front;
                    if (sum < n && record[sum-1] == 0) {
                        record[sum-1] = cnt;
                        layer.push(sum);
                    }
                    else if (sum == n)
                        return cnt;
                }
            }
        }

        return -1;
    }
};
