/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (48.59%)
 * Total Accepted:    14.5K
 * Total Submissions: 29.8K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 * 
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 * 
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 * 
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 * 
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 * 
 * 
 */
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        int l = grid[0][0], r = n * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (trySolution(grid, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
private:
    bool trySolution(vector<vector<int>> &grid, int T) {
        const int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return dfs(grid, visited, 0, 0, T);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int row, int col, int T) {
        int n = grid.size();
        vector<int> dir({-1, 0, 1, 0, -1});
        visited[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int r = row + dir[i], c = col + dir[i+1];
            if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c] && grid[r][c] <= T) {
                if (r == n-1 && c == n-1) return true;
                if (dfs(grid, visited, r, c, T)) return true;
            }
        }
        return false;
    }
};
