/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.89%)
 * Total Accepted:    123.9K
 * Total Submissions: 778.5K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
class Solution {
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2)        
            return points.size();
        int result = 0;
        //Fix one point, form a line with every other point
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<string, int> grads;
            int overlapPoints = 0, maxnm = 1, verticalPoints = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i] == points[j])
                    ++overlapPoints;
                else if (points[i][0] == points[j][0])
                    maxnm = max(maxnm, ++verticalPoints);
                else {
                    int dx = points[i][0] - points[j][0],
                        dy = points[i][1] - points[j][1];
                    int gcd = GCD(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                    int sum = 1 + ++grads[to_string(dx)+"_"+to_string(dy)];

                    maxnm = max(maxnm, sum);
                }
            }
            result = max(result, maxnm + overlapPoints);
        }
        return result;
    }
};
