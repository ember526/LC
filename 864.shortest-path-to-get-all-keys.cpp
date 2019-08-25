/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 *
 * https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (36.96%)
 * Total Accepted:    5.6K
 * Total Submissions: 15.1K
 * Testcase Example:  '["@.a.#","###.#","b.A.B"]'
 *
 * We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@"
 * is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are
 * locks.
 * 
 * We start at the starting point, and one move consists of walking one space
 * in one of the 4 cardinal directions.  We cannot walk outside the grid, or
 * walk into a wall.  If we walk over a key, we pick it up.  We can't walk over
 * a lock unless we have the corresponding key.
 * 
 * For some 1 <= K <= 6, there is exactly one lowercase and one uppercase
 * letter of the first K letters of the English alphabet in the grid.  This
 * means that there is exactly one key for each lock, and one lock for each
 * key; and also that the letters used to represent the keys and locks were
 * chosen in the same order as the English alphabet.
 * 
 * Return the lowest number of moves to acquire all keys.  If it's impossible,
 * return -1.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["@.a.#","###.#","b.A.B"]
 * Output: 8
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["@..aA","..B#.","....b"]
 * Output: 6
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 30
 * 1 <= grid[0].length <= 30
 * grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
 * The number of keys is in [1, 6].  Each key has a different letter and opens
 * exactly one lock.
 * 
 * 
 * 
 */
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // Data Structures
        const int m = grid.size(), n = grid[0].size();
        int target = 0;
        queue<int> q;
        unordered_set<int> visited;
        // Initialize
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    int state = (i << 16) | (j << 8) | 0;
                    q.push(state);
                    visited.insert(state);
                }
                else if (islower(grid[i][j]))
                    target |= 1 << (grid[i][j] - 'a');
            }
        // BFS
        int step = 0;
        const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (q.empty() == false) {
            int size = q.size();
            while (size--) {
                int state = q.front();
                q.pop();
                int i = state >> 16, j = (state >> 8) & 0xff, keys = state & 0xff;
                if (keys == target)
                    return step;
                for (const auto &dir : dirs) {
                    int y = i + dir.first, x = j + dir.second;
                    int nextkeys = keys;
                    if (y < 0 || x < 0 || y >= m || x >= n)
                        continue;
                    const char ch = grid[y][x];
                    if (ch == '#')
                        continue;
                    if (isupper(ch) && 0 == (keys & (1 << (ch - 'A'))))
                        continue;
                    if (islower(ch))
                        nextkeys |= 1 << (ch - 'a');
                    int next = (y << 16) | (x << 8) | nextkeys;
                    if (visited.count(next))
                        continue;
                    visited.insert(next);
                    q.push(next);
                    cout << y << " " << x << " " << keys << endl;
                }
            }
                cout << "----------------" << endl;
            ++step;
        }
        return -1;
    }
};
