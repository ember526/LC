/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 *
 * https://leetcode.com/problems/number-of-squareful-arrays/description/
 *
 * algorithms
 * Hard (47.71%)
 * Total Accepted:    6.2K
 * Total Submissions: 13K
 * Testcase Example:  '[1,17,8]'
 *
 * Given an array A of non-negative integers, the array is squareful if for
 * every pair of adjacent elements, their sum is a perfect square.
 * 
 * Return the number of permutations of A that are squareful.  Two permutations
 * A1 and A2 differ if and only if there is some index i such that A1[i] !=
 * A2[i].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,17,8]
 * Output: 2
 * Explanation: 
 * [1,8,17] and [17,8,1] are the valid permutations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2]
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 0 <= A[i] <= 1e9
 * 
 */
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int ans = 0;
        sort(A.begin(), A.end());
        dfs(A, ans, 0);
        return ans;
    }
private:
    void dfs(vector<int> A, int &ans, int dep) {
        auto isSquare = [](int num) {
            int r = sqrt(num);
            return r * r == num;
        };
        if (dep == A.size()) {
            ++ans;
        }
        for (int i = dep; i < A.size(); ++i) {
            if (i > dep && A[i] == A[dep])
                continue;
            swap(A[i], A[dep]);
            if (dep == 0 || isSquare(A[dep] + A[dep-1]))
                dfs(A, ans, dep + 1);
            //swap(A[i], A[dep]);
        }
        return;
    }
};
