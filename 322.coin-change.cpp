/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (30.95%)
 * Total Accepted:    213.6K
 * Total Submissions: 688.2K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int>solutions(amount + 1, 0);
        for (int e : coins)
            if (e <= amount)
                solutions[e] = 1;
        for (int i = 1; i <= amount; ++i) {
            if (solutions[i])
                continue;
            int least = 0;
            for (int e : coins)
                if (i - e >= 0 && solutions[i-e] > 0) 
                    least = least ? min(least, solutions[i-e] + 1) : solutions[i-e] + 1;
            if (least)
                solutions[i] = least;
        }
        //for (int e : solutions)
        //    cout << e << " ";
        return solutions[amount] ? solutions[amount] : -1;
    }
};
