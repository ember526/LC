/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (44.17%)
 * Total Accepted:    11.6K
 * Total Submissions: 26K
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
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        auto print = [&]() {
            for (auto &row : A) {
                for (auto e : row)
                    cout << e << " ";
                cout << endl;
            }
            cout << "$" << endl;
        };
        //Get initial queue for BFS
        queue<pair<int, int>> q;
        //DFS to locate the first island
        bool found = false;
        for (int i = 0; i < A.size() && !found; ++i)
            for (int j = 0; j < A[0].size() && !found; ++j)
                if (A[i][j]) {
                    dfs(A, i, j, q);
                    found = true;
                }
        //BFS to esclate to the second island
        int steps = 0;
        vector<int> dirs{0, 1, 0, -1, 0};
        while (q.empty() == false) {
        //print();
            int size = q.size();
            while (size--) {
                int y = q.front().first,
                    x = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dirs[i],
                        nx = x + dirs[i+1];
                    if (nx < 0 || ny < 0 || ny >= A.size() || nx >= A[0].size()
                            || A[ny][nx] == 2)
                        continue;
                    if (A[ny][nx] == 1)
                        return steps;
                    A[ny][nx] = 2;
                    q.emplace(ny, nx);

                }
            }
            ++steps;
        }

        return -1;
    }
private:
    void dfs(vector<vector<int>> &A, int y, int x, queue<pair<int, int>> &q) {
        if (y < 0 || x < 0 || y >= A.size() || x >= A[0].size() || A[y][x] != 1)
            return;
        A[y][x] = 2;
        q.emplace(y, x);
        dfs(A, y + 1, x, q);
        dfs(A, y - 1, x, q);
        dfs(A, y, x - 1, q);
        dfs(A, y, x + 1, q);
        return;
    }

};
