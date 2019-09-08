/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.06%)
 * Total Accepted:    414.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        int size = lists.size();
        while (size != 1) {
            int nextsz = 0;
            for (int i = 0, j = 0; i < size; i += 2, ++j) {
                if (i + 1 < size)
                    lists[j] = merge2Lists(lists[i], lists[i+1]);
                else
                    lists[j] = lists[i];
                ++nextsz;
            }
            size = nextsz;
        }
        return lists[0];
    }
private:
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        while (l1) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }

        return dummy.next;
    }
};
