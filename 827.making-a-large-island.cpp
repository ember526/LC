/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (43.46%)
 * Total Accepted:    10.5K
 * Total Submissions: 24.2K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
 * 
 * After, what is the size of the largest island? (An island is a
 * 4-directionally connected group of 1s).
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 0], [0, 1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1, 1], [1, 0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 * 
 * Example 3:
 * 
 * 
 * Input: [[1, 1], [1, 1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * 1 <= grid.length = grid[0].length <= 50.
 * 0 <= grid[i][j] <= 1.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> color{0, 0};
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    color.push_back(paint(grid, i, j, color.size()));

        int maxarea = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 0) {
                    unordered_set<int> kinds {get(grid, i - 1, j), get(grid, i + 1, j),
                        get(grid, i, j - 1), get(grid, i, j + 1)};
                    maxarea = max(maxarea, 
                            1 + accumulate(kinds.begin(), kinds.end(), 0, [&](int a, int b){ return a + color[b];}));
                }
        return maxarea ? maxarea : color.back();
    }
private:
    int get(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        return grid[i][j];
    }

    int paint (vector<vector<int>> &grid, int i, int j, int color) {
        if (get(grid, i, j) != 1)
            return 0;
        grid[i][j] = color;
        return 1 + paint(grid, i - 1, j, color) + paint(grid, i + 1, j, color) +
                paint(grid, i, j - 1, color) + paint(grid, i, j + 1, color);
    }
};
