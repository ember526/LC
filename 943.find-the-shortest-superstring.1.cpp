/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 *
 * https://leetcode.com/problems/find-the-shortest-superstring/description/
 *
 * algorithms
 * Hard (38.45%)
 * Total Accepted:    5.1K
 * Total Submissions: 13.1K
 * Testcase Example:  '["alex","loves","leetcode"]'
 *
 * Given an array A of strings, find any smallest string that contains each
 * string in A as a substring.
 * 
 * We may assume that no string in A is substring of another string in A.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["alex","loves","leetcode"]
 * Output: "alexlovesleetcode"
 * Explanation: All permutations of "alex","loves","leetcode" would also be
 * accepted.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
 * Output: "gctaagttcatgcatc"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 1 <= A[i].length <= 20
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        auto dist = [](string& a, string& b) {
            int d = min(a.length(), b.length());
            while (d > 0) {
                if (a.substr(a.size() - d) == b.substr(0, d))
                    break;
                --d;
            }
            return b.length() - d;
        };
        
        const int n = A.size();
        vector<vector<int>> g_(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g_[i][j] = dist(A[i], A[j]);

        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = A[i].length();

        for (int s = 1; s < (1 << n); ++s) {
            for (int i = 0; i < n; ++i) {
                if (!(s & (1 << i)))
                    continue;
                int prev_state = s - (1 << i);
                for (int j = 0; j < n; ++j) {
                    if (dp[prev_state][j] + g_[j][i] < dp[s][i]) {
                        dp[s][i] = dp[prev_state][j] + g_[j][i];
                        parent[s][i] = j;
                    }
                }
            }
        }

        auto it = min_element(begin(dp.back()), end(dp.back()));
        int cur = it - begin(dp.back());
        int s = (1 << n) - 1;
        string result;
        while (s) {
            int prev = parent[s][cur];
            if (prev < 0)
                result = A[cur] + result;
            else
                result = A[cur].substr(A[cur].length() - g_[prev][cur]) + result;
            s &= ~(1 << cur);
            cur = prev;
        }

        return result;
    }
};
