/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.76%)
 * Total Accepted:    244.8K
 * Total Submissions: 795.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int up = 0, down = matrix.size() - 1, 
            left = 0, right = matrix[0].size() - 1;            
        vector<int> result;
        while (true) {
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[up][i]);
            if (++up > down)
                break;
            for (int i = up; i <= down; ++i)
                result.push_back(matrix[i][right]);
            if (--right < left)
                break;
            for (int i = right; i >= left; --i)
                result.push_back(matrix[down][i]);
            if (--down < up)
                break;
            for (int i = down; i >= up; --i)
                result.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return result;
    }
};
