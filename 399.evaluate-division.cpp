/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (47.90%)
 * Total Accepted:    87.8K
 * Total Submissions: 182K
 * Testcase Example:  '[["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //Build the graph : g[A][B] : A / B
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < equations.size(); ++i) {
            const string &A = equations[i][0];
            const string &B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }
        
        vector<double> result;
        for (const auto &q : queries) {
            const string &X = q[0];
            const string &Y = q[1];
            if (!g.count(X) || !g.count(Y)) {
                result.push_back(-1);
                continue;
            }
            unordered_set<string> visited;
            result.push_back(dfs(g, X, Y, visited));
        }

        return result;
    }
private:
    double dfs(unordered_map<string, unordered_map<string, double>> &g,
            const string &A, const string &B, 
            unordered_set<string> &visited) {
        if (A == B)
            return 1;
        visited.insert(A);
        for (auto &divisor : g[A]) {
            const string &C = divisor.first;
            if (visited.count(C))
                continue;
            double d = dfs(g, C, B, visited);
            if (d > 0)
                return d * divisor.second;
        }
        return -1;
    }
};
