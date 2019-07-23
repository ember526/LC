/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (50.05%)
 * Total Accepted:    79.5K
 * Total Submissions: 158.1K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * 
 * 
 */
class Solution {
    vector<int> ori, arr;
public:
    Solution(vector<int>& nums) {
        //intialize the random (pseudo) number generator
        //actually, the sequence of numbers has been generated at this time
        srand(time(NULL));
        ori = nums;
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = ori;
        return ori; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = arr.size() - 1; i >= 0; --i) {
            int index = rand() % (i + 1);
            swap(arr[i], arr[index]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
