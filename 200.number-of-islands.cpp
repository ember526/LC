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
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int count = 0;
        for (size_t i = 0; i < grid.size(); ++i)
            for (size_t j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
        return count;
    }
private:
    void dfs(vector<vector<char> > &grid, size_t i, size_t j) {
        grid[i][j] = '#';
        if (i > 0 && grid[i-1][j] == '1')
            dfs(grid, i - 1, j);
        if (j > 0 && grid[i][j-1] == '1')
            dfs(grid, i, j - 1);
        if (i < grid.size() - 1 && grid[i+1][j] == '1')
            dfs(grid, i + 1, j);
        if (j < grid[0].size() - 1 && grid[i][j+1] == '1')
            dfs(grid, i, j + 1);
        return;
    }
};
