/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (46.59%)
 * Total Accepted:    263.5K
 * Total Submissions: 565.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;
        result.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp = {1};
            const vector<int> & lastRow = result[i-1];
            for (int vi = 0; vi < lastRow.size()-1; ++vi) 
                tmp.push_back(lastRow[vi] + lastRow[vi+1]);
            tmp.push_back(1);
            result.push_back(tmp); 
        }
        return result;
    }
};
