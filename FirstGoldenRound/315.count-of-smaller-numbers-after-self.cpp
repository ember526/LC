/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.52%)
 * Total Accepted:    81.3K
 * Total Submissions: 210.6K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */
class Solution {
    void mergesort(vector<int>&index, int first, int last, vector<int>&result, vector<int>&nums) {
        int count = last - first;
        if (count <= 1)
            return;
        int mid = first + (last - first) / 2;
        mergesort(index, first, mid, result, nums);
        mergesort(index, mid, last, result, nums);
        vector<int> tmp;
        int li = first, ri = mid, semicount = 0;
        while (li < mid || ri < last) {
            if (ri == last|| (li < mid && nums[index[li]] <= nums[index[ri]])) {
                tmp.push_back(index[li]);
                result[index[li]] += semicount;
                ++li;
            }
            else {
                tmp.push_back(index[ri]);
                ++semicount;
                ++ri;
            }
        }
        move(tmp.begin(), tmp.end(), index.begin() + first);
        return;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size()), index(nums.size());
        iota(index.begin(), index.end(), 0);
        mergesort(index, 0, nums.size(), result, nums);
        return result;
    }
};
