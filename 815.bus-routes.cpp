/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (40.52%)
 * Total Accepted:    23.9K
 * Total Submissions: 58.9K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * We have a list of bus routes. Each routes[i] is a bus route that the i-th
 * bus repeats forever. For example if routes[0] = [1, 5, 7], this means that
 * the first bus (0-th indexed) travels in the sequence
 * 1->5->7->1->5->7->1->... forever.
 * 
 * We start at bus stop S (initially not on a bus), and we want to go to bus
 * stop T. Travelling by buses only, what is the least number of buses we must
 * take to reach our destination? Return -1 if it is not possible.
 * 
 * 
 * Example:
 * Input: 
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * Output: 2
 * Explanation: 
 * The best strategy is take the first bus to the bus stop 7, then take the
 * second bus to the bus stop 6.
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 500.
 * 0 <= routes[i][j] < 10 ^ 6.
 * 
 * 
 */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        /* Data Structures */
        unordered_map<int, vector<int>> stops_;
        queue<int> q_;
        int count = 0;
        vector<int> visited(routes.size(), 0);
        /* Initialization */
        for (int i = 0; i < routes.size(); ++i)
            for(int stop : routes[i])
                stops_[stop].push_back(i);
        q_.push(S);
        /* BFS */
        while (q_.empty() == false) {
            int size = q_.size();
            while (size--) {
                int cur = q_.front();
                q_.pop();
                if (cur == T)
                    return count;
                for (int bus : stops_[cur]) {
                    if (visited[bus])
                        continue;
                    visited[bus] = 1;
                    for (int next : routes[bus])
                        q_.push(next);
                }
            }
            ++count;
        }
        return -1;
    }
};
