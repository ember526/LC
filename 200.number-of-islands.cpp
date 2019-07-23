/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.01%)
 * Total Accepted:    380.5K
 * Total Submissions: 904.2K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
    void extend(vector<vector<char>>& grid, pair<int, int> origin) {
        queue<pair<int, int>> todo;
        todo.push(origin);
        while (todo.empty() == false) {
            auto pos = todo.front();
            todo.pop();
            int i = pos.first, j = pos.second; 
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1') {
                grid[i][j] = '#';
                todo.push({i + 1, j});
                todo.push({i - 1, j});
                todo.push({i, j + 1});
                todo.push({i, j - 1});
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1') {
                    ++result;
                    extend(grid, {i, j});
                }
        for (auto &row : grid)
            for (auto &ch : row)
                if (ch == '#')
                    ch = '1';
        return result;
    }
};
