/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.04%)
 * Likes:    1544
 * Dislikes: 107
 * Total Accepted:    222.6K
 * Total Submissions: 611.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        for (int i = 0; i + 1 < m ; ++i)
            head = head->next;
        auto p = head->next, next = p->next;
        for (int i = m; i < n; ++i) {
            auto tmp = next;
            next = next->next;
            tmp->next = p;
            p = tmp;
        }
        head->next->next = next;
        head->next = p;
        return dummy.next;
    }        
};
// @lc code=end
