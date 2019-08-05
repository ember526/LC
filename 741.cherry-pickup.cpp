/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 *
 * https://leetcode.com/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (30.13%)
 * Total Accepted:    11.1K
 * Total Submissions: 36.5K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * In a N x N grid representing a field of cherries, each cell is one of three
 * possible integers.
 * 
 * 
 * 
 * 
 * 0 means the cell is empty, so you can pass through;
 * 1 means the cell contains a cherry, that you can pick up and pass
 * through;
 * -1 means the cell contains a thorn that blocks your way.
 * 
 * 
 * 
 * 
 * Your task is to collect maximum number of cherries possible by following the
 * rules below:
 * 
 * 
 * 
 * 
 * Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or
 * down through valid path cells (cells with value 0 or 1);
 * After reaching (N-1, N-1), returning to (0, 0) by moving left or up through
 * valid path cells;
 * When passing through a path cell containing a cherry, you pick it up and the
 * cell becomes an empty cell (0);
 * If there is no valid path between (0, 0) and (N-1, N-1), then no cherries
 * can be collected.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0, 1, -1],
 * ⁠[1, 0, -1],
 * ⁠[1, 1,  1]]
 * Output: 5
 * Explanation: 
 * The player started at (0, 0) and went down, down, right right to reach (2,
 * 2).
 * 4 cherries were picked up during this single trip, and the matrix becomes
 * [[0,1,-1],[0,0,-1],[0,0,0]].
 * Then, the player went left, up, up, left to return home, picking up one more
 * cherry.
 * The total number of cherries picked up is 5, and this is the maximum
 * possible.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * grid is an N by N 2D array, with 1 <= N <= 50.
 * Each grid[i][j] is an integer in the set {-1, 0, 1}.
 * It is guaranteed that grid[0][0] and grid[N-1][N-1] are not
 * -1.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int n = grid.size();
        m_ = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::min())));
        return max(0, move(grid, n - 1, n - 1, n - 1));
    }
private:
    vector<vector<vector<int>>> m_;
    int move(const vector<vector<int>> &grid, int x1, int y1, int x2) {
        int y2 = x1 + y1 - x2;
        if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
            return -1;
        if (grid[y1][x1] == -1 || grid[y2][x2] == -1)
            return -1;
        if (x1 == 0 && y1 == 0)
            return grid[0][0];
        if (m_[x1][y1][x2] != numeric_limits<int>::min())
            return m_[x1][y1][x2];
        int ans = max(max(move(grid, x1 - 1, y1, x2), move(grid, x1 - 1, y1, x2 - 1)), 
                      max(move(grid, x1, y1 - 1, x2), move(grid, x1, y1 - 1, x2 - 1)));
        if  (ans < 0)
            return m_[x1][y1][x2] = -1;
        ans += grid[y1][x1];
        if (x1 != x2)
            ans += grid[y2][x2];
        return m_[x1][y1][x2] = ans;
    }
};
