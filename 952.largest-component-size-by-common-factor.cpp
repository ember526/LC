/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 *
 * https://leetcode.com/problems/largest-component-size-by-common-factor/description/
 *
 * algorithms
 * Hard (26.57%)
 * Total Accepted:    5.2K
 * Total Submissions: 19.7K
 * Testcase Example:  '[4,6,15,35]'
 *
 * Given a non-empty array of unique positive integers A, consider the
 * following graph:
 * 
 * 
 * There are A.length nodes, labelled A[0] to A[A.length - 1];
 * There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a
 * common factor greater than 1.
 * 
 * 
 * Return the size of the largest connected component in the graph.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,6,15,35]
 * Output: 4
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [20,50,9,63]
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [2,3,6,7,4,12,21,39]
 * Output: 8
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= 100000
 * 
 * 
 * 
 * 
 * 
 */
class DSU {
public:
    DSU(int n) : p_(n) {
        iota(p_.begin(), p_.end(), 0);
    }

    void Union(int x, int y) {
        p_[Find(x)] = p_[Find(y)];
    }

    int Find(int x) {
        if (p_[x] != x)
            p_[x] = Find(p_[x]);
        return p_[x];
    }
private:
    vector<int> p_;
};
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        DSU dsu(n + 1);
        for (int a : A)
            for (int k = 2; k <= sqrt(a); ++k)
                if (a % k == 0) {
                    dsu.Union(a, k);
                    dsu.Union(a, a / k);
                }
        unordered_map<int, int> count;
        int ans = 1;
        for (int a : A)
            ans = max(ans, ++count[dsu.Find(a)]);
        return ans;
    }
private:
};
