/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (36.02%)
 * Total Accepted:    192.9K
 * Total Submissions: 534.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        int length = 0;
        auto p = head;
        while (p) {
            ++length;
            p = p->next;
        }
        head = sort(head, length);
        return head;
    }
private:
    ListNode *sort(ListNode *head, int length) {
        if (length == 1)
            return head;
        if (length == 2) {
            if (head->val < head->next->val)
                return head;
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            return tmp;
        }
                int llength = length / 2, rlength = length - llength;
        ListNode *iter = head, *rhead = NULL;
        for (int i = 0; i < llength - 1; ++i)
            iter = iter->next;
        rhead = iter->next;
        iter->next = NULL;
        head = sort(head, llength),
        rhead = sort(rhead, rlength);

        return merge(head, rhead);
        int llen = length / 2, rlen = length - llen;
        ListNode *p = head;
        for (int i = 0; i < llen - 1; ++i)
            p = p->next;
        auto right = p->next, left = sort(head, llen);
        p->next = NULL;
        right = sort(right, rlen);
        return merge(left, right);
    }

    ListNode *merge(ListNode *l, ListNode *r) {
        ListNode head(0), *cur = &head;
        while (l && r) {
            if (l->val <= r->val) {
                cur->next = l;
                l = l->next;
            }
            else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l ? l : r;
        return head.next;
    }
};
