/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.12%)
 * Total Accepted:    245K
 * Total Submissions: 696.4K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int up = 0, down = matrix.size() - 1;
        if (target < matrix[0][0])
            return false;
        while (up < down) {
            int mid = up + (down - up + 1) / 2;
            if (target >= matrix[mid][0])
                up = mid;
            else
                down = mid - 1;
        }

        int row = up;
        int l = 0, r = matrix[0].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};
