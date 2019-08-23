/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 *
 * https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
 *
 * algorithms
 * Hard (47.82%)
 * Total Accepted:    9.3K
 * Total Submissions: 19.4K
 * Testcase Example:  '[[1,2,3],[0],[0],[0]]'
 *
 * An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is
 * given as graph.
 * 
 * graph.length = N, and j != i is in the list graph[i] exactly once, if and
 * only if nodes i and j are connected.
 * 
 * Return the length of the shortest path that visits every node. You may start
 * and stop at any node, you may revisit nodes multiple times, and you may
 * reuse edges.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[0],[0],[0]]
 * Output: 4
 * Explanation: One possible path is [1,0,2,0,3]
 * 
 * Example 2:
 * 
 * 
 * Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
 * Output: 4
 * Explanation: One possible path is [0,1,4,2,3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= graph.length <= 12
 * 0 <= graph[i].length < graph.length
 * 
 * 
 */
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        /* BFS */
        /* Data Structures */
        queue<pair<int, int>> q;                        //BFS queue, {node, visited}
        unordered_set<int> v;                           //Visited states, node<<i | visited
        const int terminal = (1 << graph.size()) - 1;
        /* Initialization */
        for (int i = 0; i < graph.size(); ++i)
            q.push({i, 1 << i});

        /* Doing BFS */
        int step = 0;
        while (q.empty() == false) {
            int size = q.size();
            while (size--) {
                int node = q.front().first,
                    visited = q.front().second;
                q.pop();
                int state = (node << 16) | visited;
                if (v.count(state))
                    continue;
                v.insert(state);
                if (visited == terminal)
                    return step;
                for (int next : graph[node])
                    q.push({next, visited | (1 << next)});
            }
            ++step;
        }
        return -1;
    }
};
