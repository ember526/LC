/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (44.30%)
 * Total Accepted:    97.9K
 * Total Submissions: 220.1K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n + 1), cd(n + 1), wait(n + 1);
        hold[0] = numeric_limits<int>::min();
        cd[0] = -1;
        wait[0] = 0;
        for (int i = 1; i <= n; ++i) {
            hold[i] = max(wait[i-1] - prices[i-1], hold[i-1]);
            cd[i] = hold[i-1] + prices[i-1];
            wait[i] = max(wait[i-1], cd[i-1]);
        }
        return max(cd[n], wait[n]);
    }
};
