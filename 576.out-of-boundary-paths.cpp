/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (32.39%)
 * Total Accepted:    18.9K
 * Total Submissions: 58K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 109 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 * 
 * 
 */
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int module = 1000000007;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        dp[i][j] = 1;
        int paths = 0;
        for (int step = 0; step < N; ++step) {
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            for (int r = 0; r < m; ++r)
                for (int c = 0; c < n; ++c)
                    for (auto &move : moves) {
                        int x = c + move[1],
                            y = r + move[0];
                        if (x < 0 || y < 0 || x >= n || y >= m)
                            paths = (paths + dp[r][c]) % module;
                        else
                            tmp[y][x] = (tmp[y][x] + dp[r][c]) % module;
                    }
            dp.swap(tmp); 
        }
        return paths;
    }
};
