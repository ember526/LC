/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (44.78%)
 * Likes:    385
 * Dislikes: 29
 * Total Accepted:    14.2K
 * Total Submissions: 31.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // First Find the island
        bool found = false;
        queue<pair<int, int>> q;
        for (int i = 0; i < A.size() && !found; ++i)
            for (int j = 0; j < A[0].size() && !found; ++j)
                if (A[i][j] == 1) {
                    Dfs(A, i, j, q);
                    found = true;
                }
        // Expand the island
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int step = 0;
        while (q.empty() == false) {
            ++step;
            int size = q.size();
            while (size--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (const auto &dir : dirs) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni < 0 || nj < 0 || ni >= A.size() || nj >= A[0].size() ||
                            A[ni][nj] == 2)
                        continue;
                    if (A[ni][nj] == 1)
                        return step - 1;
                    A[ni][nj] = 2;
                    q.emplace(ni, nj);
                }
            }
        }
        return -1;
    }
private:
    void Dfs(vector<vector<int>> &A, int i, int j, queue<pair<int, int>> &q) {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] != 1)
            return;
        A[i][j] = 2;
        q.emplace(i, j);
        Dfs(A, i - 1, j, q);
        Dfs(A, i + 1, j, q);
        Dfs(A, i, j - 1, q);
        Dfs(A, i, j + 1, q);
        return;
    }
};
// @lc code=end
