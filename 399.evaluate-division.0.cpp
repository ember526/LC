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
        unordered_map<string, pair<string, double>> parents;

        for (int i = 0; i < equations.size(); ++i) {
            const string &A = equations[i][0];
            const string &B = equations[i][1];
            double k = values[i];
            // New union
            if (!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            }
            else if (!parents.count(A))
                parents[A] = {B, k};
            else if (!parents.count(B))
                parents[B] = {A, 1.0 / k};
            else {
                auto &rA = find(A, parents);
                auto &rB = find(B, parents);
                parents[rA.first] = {rB.first, k / rA.second * rB.second};
            }
        }
        vector<double> result;
        for (const auto &query : queries) {
            const string &X = query[0];
            const string &Y = query[1];
            if (!parents.count(X) || !parents.count(Y)) {
                result.push_back(-1.0);
                continue;
            }
            auto &rX = find(X, parents);
            auto &rY = find(Y, parents);
            if (rX.first != rY.first)
                result.push_back(-1.0);
            else
                result.push_back(rX.second / rY.second);
        }
        return result;
    }
private:
    pair<string, double> &find(const string &child, unordered_map<string, pair<string, double>> &parents) {
        if (child != parents[child].first) {
            const auto &parent = find(parents[child].first, parents);
            parents[child].first = parent.first;
            parents[child].second *= parent.second;
        }
        return parents[child];
    }
};
