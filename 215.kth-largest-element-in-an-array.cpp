/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (48.39%)
 * Total Accepted:    394.3K
 * Total Submissions: 812.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int kth;
        vector<int> tmp = nums;
        int left = 0, right = nums.size() - 1; 
        while (true) {        
            int idx = partition(tmp, left, right);
            if (idx == k - 1)
                return tmp[idx];
            if (idx > k - 1)
                right = idx - 1;
            else
                left = idx + 1;
        }
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) { // the constraints here is crucial
           if (nums[l] < pivot && nums[r] > pivot) // make sure that this case is placed before the other two, otherwise there will be problems
               swap(nums[r--], nums[l++]);
           if (nums[l] >= pivot)
               ++l;
           if (nums[r] <= pivot)
               --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
