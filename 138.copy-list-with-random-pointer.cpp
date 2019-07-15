/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (27.70%)
 * Total Accepted:    257.6K
 * Total Submissions: 928.2K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You must return the copy of the given head as a reference to the cloned
 * list.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node *iter = head;
        while (iter) {
            Node *tmp = new Node(iter->val, iter->next, iter->random);
            iter->next = tmp;
            iter = iter->next->next;
        }
        iter = head;
        while (iter) {
            Node *newIter = iter->next;
            newIter->random = newIter->random ? newIter->random->next : NULL;
            iter = newIter->next;
        }

        iter = head;
        Node *newHead = head->next;
        while (iter) {
            Node *newIter = iter->next;
            Node *tmp = newIter->next;
            newIter->next = tmp ? tmp->next : NULL;
            iter->next = tmp;
            iter = tmp;
        }
        return newHead;
    }
};
