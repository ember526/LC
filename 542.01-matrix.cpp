/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (36.11%)
 * Total Accepted:    49.1K
 * Total Submissions: 134.9K
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
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0)
                    q.emplace(i, j);
        int dis = 0;
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            ++dis;
            int size = q.size();
            while (size--) {
                int y = q.front().first,
                    x = q.front().second;
                q.pop();
                for (auto &dir : dirs) {
                    int i = y + dir[0],
                        j = x + dir[1];
                    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] != 1)
                        continue;
                    matrix[i][j] = dis == 1 ? -1 : dis;
                    q.emplace(i, j);
                }
            }
        }
        for (auto &row : matrix)
            for (auto &e : row)
                if (e == -1)
                    e = 1;
        return matrix;
    }
};
