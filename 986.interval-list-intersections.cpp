/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (63.97%)
 * Likes:    531
 * Dislikes: 24
 * Total Accepted:    39K
 * Total Submissions: 60.7K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 * 
 * Return the intersection of these two interval lists.
 * 
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.  The intersection of two closed intervals is a
 * set of real numbers that is either empty, or can be represented as a closed
 * interval.  For example, the intersection of [1, 3] and [2, 4] is [2,
 * 3].)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects,
 * and not arrays or lists.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        for (const auto &a : A)
            for (const auto &b : B)
                getIntsct(result, a, b);
        return result;
    }

private:
    void getIntsct(vector<vector<int>> &result, const vector<int> &a, const vector<int> &b) {
        if (a[0] > b[1] || a[1] < b[0])
            return;
        int lo = max(a[0], b[0]), hi = min(a[1], b[1]);
        result.push_back({lo, hi});
        return;
    }
};
// @lc code=end
