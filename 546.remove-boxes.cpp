/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 *
 * https://leetcode.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (38.58%)
 * Total Accepted:    10K
 * Total Submissions: 25.8K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]'
 *
 * Given several boxes with different colors represented by different positive
 * numbers. 
 * You may experience several rounds to remove boxes until there is no box
 * left. Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k*k points.
 * Find the maximum points you can get.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 * 
 * Output:
 * 
 * 23
 * 
 * Explanation: 
 * 
 * [1, 3, 2, 2, 2, 3, 4, 3, 1] 
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
 * ----> [1, 3, 3, 3, 1] (1*1=1 points) 
 * ----> [1, 1] (3*3=9 points) 
 * ----> [] (2*2=4 points)
 * 
 * 
 * 
 * Note:
 * The number of boxes n would not exceed 100.
 * 
 * 
 */
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        const int n = boxes.size();
        m_ = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return remove(boxes, 0, n - 1, 0);
    }
private:
    vector<vector<vector<int>>> m_;
    int remove(const vector<int> &boxes, int l, int r, int k) {
        if (l > r)
            return 0;
        if (m_[l][r][k])
            return m_[l][r][k];
        int r_old = r;
        while (l < r && boxes[r] == boxes[r-1]) {
            --r;
            ++k;
        }
        m_[l][r][k] = remove(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i)
            if (boxes[i] == boxes[r])
                m_[l][r][k] = max(m_[l][r][k], remove(boxes, l, i, k + 1) + remove(boxes, i + 1, r - 1, 0));
        for (int i = 0; i <= r_old - r; ++i)
            m_[l][r+i][k-i] = m_[l][r][k];
        return m_[l][r][k];
    }
};
