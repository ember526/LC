/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (55.51%)
 * Total Accepted:    220.2K
 * Total Submissions: 395.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int e : nums)
            ++freq[e];
        typedef unordered_map<int, int>::iterator mapiter;

        auto cmp = [] (mapiter i1, mapiter i2) { return i1->second > i2->second; };
        priority_queue<mapiter, vector<mapiter>, decltype(cmp)> heap(cmp);
        for (mapiter iter = freq.begin(); iter != freq.end(); ++iter) {
            heap.push(iter);
            if (heap.size() > k)
                heap.pop();
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = heap.top()->first;
            heap.pop();
        }
        
        return result;
    }
};
