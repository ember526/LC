/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (66.57%)
 * Total Accepted:    82.6K
 * Total Submissions: 123.6K
 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 * 
 * Example:
 * 
 * 
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 * 
 * 
 * 
 * 
 */
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        nums = vector<int>(size, 0);
        idx = 0;
        sum = 0;
        len = size;
        curlen = 0;
    }
    
    double next(int val) {
        sum = sum - nums[idx] + val;
        nums[idx] = val;
        idx = (idx + 1) % len;
        curlen = curlen + 1 > len ? len : curlen + 1;
        return (double)sum / curlen;
    }
private:
    vector<int> nums;
    int curlen;
    int idx;
    int sum;
    int len;
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
