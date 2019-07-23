/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.07%)
 * Total Accepted:    217.5K
 * Total Submissions: 515.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxlen = 0;
        for (int e : nums) {
            if (set.find(e - 1) == set.end() && set.find(e) != set.end()) {
                int tmp = e + 1;
                while (set.find(tmp) != set.end())
                    ++tmp;
                maxlen = max(maxlen, tmp - e);
            }
        }
        return maxlen;
    }
};
