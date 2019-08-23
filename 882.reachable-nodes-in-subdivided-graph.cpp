/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 *
 * https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/
 *
 * algorithms
 * Hard (38.57%)
 * Total Accepted:    3.7K
 * Total Submissions: 9.7K
 * Testcase Example:  '[[0,1,10],[0,2,1],[1,2,2]]\n6\n3'
 *
 * Starting with an undirected graph (the "original graph") with nodes from 0
 * to N-1, subdivisions are made to some of the edges.
 * 
 * The graph is given as follows: edges[k] is a list of integer pairs (i, j, n)
 * such that (i, j) is an edge of the original graph,
 * 
 * and n is the total number of new nodes on that edge. 
 * 
 * Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1,
 * x_2, ..., x_n) are added to the original graph,
 * 
 * and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n),
 * (x_n, j) are added to the original graph.
 * 
 * Now, you start at node 0 from the original graph, and in each move, you
 * travel along one edge. 
 * 
 * Return how many nodes you can reach in at most M moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
 * Output: 13
 * Explanation: 
 * The nodes that are reachable in the final graph after M = 6 moves are
 * indicated below.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
 * Output: 23
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= edges.length <= 10000
 * 0 <= edges[i][0] < edges[i][1] < N
 * There does not exist any i != j for which edges[i][0] == edges[j][0] and
 * edges[i][1] == edges[j][1].
 * The original graph has no parallel edges.
 * 0 <= edges[i][2] <= 10000
 * 0 <= M <= 10^9
 * 1 <= N <= 3000
 * A reachable node is a node that can be travelled to using at most M moves
 * starting from node 0.
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        /* Part I: Doing the Dijkstra, calculating shortest path from src to every other node */ 
        /* Data Structures */
        priority_queue<pair<int, int>> q;               //Shortest Path, <HP, node>
        unordered_map<int, unordered_map<int, int>>g_;  //Adjacent table of the graph
        unordered_map<int, int> hp_;                    //node->hp, max mp for each reachable nodes
        /* Initialization */
        q.push(make_pair(M, 0));
        for (const auto &e : edges)
            g_[e[0]][e[1]] = g_[e[1]][e[0]] = e[2];
        /* Dijkstra */
        while (q.empty() == false) {
            int node = q.top().second, HP = q.top().first;
            q.pop();
            if (hp_.count(node))
                continue;
            hp_[node] = HP;
            for (const auto& e: g_[node]) {
                int next = e.first;
                int n_hp = HP - e.second - 1;
                if (hp_.count(next) || n_hp < 0)
                    continue;
                q.push(make_pair(n_hp, next));
            }
        }
        //Part II: Determine which nodes can be covered
        int result = hp_.size();
        for (const auto &e : edges) {
            int u = hp_.count(e[0]) ? hp_[e[0]] : 0,
                v = hp_.count(e[1]) ? hp_[e[1]] : 0;
            result += min(u + v, e[2]);
        }
        
        return result;
    }
};
