/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (36.89%)
 * Likes:    870
 * Dislikes: 87
 * Total Accepted:    56.4K
 * Total Submissions: 151.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0)
                    q.push({i, j});
        vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int step = 0;
        while (q.empty() == false) {
            int size = q.size();
            ++step;
            while (size--) {
                int i = q.front().first,
                    j = q.front().second;
                q.pop();
                for (const auto &dir : dirs) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size() ||
                            matrix[ni][nj] != 1)
                        continue;
                    q.push({ni, nj});
                    matrix[ni][nj] = step == 1 ? -1 : step;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1;
        return matrix;
    }
};
// @lc code=end
