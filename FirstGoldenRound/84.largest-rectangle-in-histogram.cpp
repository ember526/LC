/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (31.56%)
 * Total Accepted:    183.5K
 * Total Submissions: 580.1K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int itop = s.top();
                s.pop();
                int length = s.empty() ? i : i - s.top() - 1;
                int area = heights[itop] * length;
                maxArea = max(maxArea, area);
            }
            s.push(i);
        }

        while (s.empty() == false) {
            int itop = s.top();
            s.pop();
            int length = s.empty() ? heights.size() : heights.size() - s.top() - 1;
            int area = heights[itop] * length;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
