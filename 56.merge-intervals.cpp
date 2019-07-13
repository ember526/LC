/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.98%)
 * Total Accepted:    368.1K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
class Solution {
private:
    void increment(vector<vector<int>> &merged, vector<int> newOne) {
        int i = 0;
        while (i < merged.size()) {
            if (merged[i][0] > newOne[1]) {
                merged.insert(merged.begin() + i, newOne);
                return;
            }
            if (merged[i][1] < newOne[0]) {
                ++i;
                continue;
            }
            merged[i][0] = min(merged[i][0], newOne[0]);
            merged[i][1] = max(merged[i][1], newOne[1]);
            for (int j = i + 1; j < merged.size(); ++j) {
                if (merged[i][1] >= merged[j][0]) {
                    merged[i][1] = max(merged[i][1], merged[j][1]);
                    merged.erase(merged.begin() + j--);
                }
                else 
                    break;
            }
            return;
        }
        merged.push_back(newOne);
        return;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        for (auto i : intervals)
            increment(merged, i);
        return merged;
    }
};
