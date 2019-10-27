/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 *
 * https://leetcode.com/problems/prison-cells-after-n-days/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    212
 * Dislikes: 394
 * Total Accepted:    25.4K
 * Total Submissions: 66.6K
 * Testcase Example:  '[0,1,0,1,1,0,0,1]\n7'
 *
 * There are 8 prison cells in a row, and each cell is either occupied or
 * vacant.
 * 
 * Each day, whether the cell is occupied or vacant changes according to the
 * following rules:
 * 
 * 
 * If a cell has two adjacent neighbors that are both occupied or both vacant,
 * then the cell becomes occupied.
 * Otherwise, it becomes vacant.
 * 
 * 
 * (Note that because the prison is a row, the first and the last cells in the
 * row can't have two adjacent neighbors.)
 * 
 * We describe the current state of the prison in the following way: cells[i]
 * == 1 if the i-th cell is occupied, else cells[i] == 0.
 * 
 * Given the initial state of the prison, return the state of the prison after
 * N days (and N such changes described above.)
 * 
 * 
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
 * Input: cells = [0,1,0,1,1,0,0,1], N = 7
 * Output: [0,0,1,1,0,0,0,0]
 * Explanation: 
 * The following table summarizes the state of the prison on each day:
 * Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
 * Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
 * Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
 * Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
 * Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
 * Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
 * Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
 * Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
 * Output: [0,0,1,1,1,1,1,0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * cells.length == 8
 * cells[i] is in {0, 1}
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unsigned char today = 0;
        for (int i = 0; i < 8; ++i)
            if (cells[7-i])
                today |= 1 << i;
        int nth = 0;
        while (nth < N) {
            ++nth;
            today = getNextDay(today);
            if (dict_.find(today) != dict_.end()) {
                int lastSeen = dict_[today];
                int circle = nth - lastSeen;
                int leftDays = N - nth;
                int idx = leftDays % circle;
                while (idx--)
                    today = getNextDay(today);
                break;
            }
            dict_[today] = nth;
        }
        vector<int> result(8, 0);
        for (int i = 0; i < 8; ++i)
            result[7-i] = (today & (1 << i)) ? 1 : 0;
        return result;
    }

private:
    unordered_map<unsigned char, int> dict_;
    int getNextDay(unsigned char today) {
        unsigned char next = 0;
        for (int i = 1; i < 7; ++i)
            next |= ((today >> (i + 1)) & 1) == ((today >> (i - 1)) & 1) ? (1 << i) : 0;
        return next;
    }       
};
// @lc code=end
