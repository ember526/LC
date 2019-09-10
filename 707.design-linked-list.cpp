/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Easy (21.11%)
 * Total Accepted:    33.3K
 * Total Submissions: 159K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your implementation of the linked list. You can choose to use the
 * singly linked list or the doubly linked list. A node in a singly linked list
 * should have two attributes: val and next. val is the value of the current
 * node, and next is a pointer/reference to the next node. If you want to use
 * the doubly linked list, you will need one more attribute prev to indicate
 * the previous node in the linked list. Assume all nodes in the linked list
 * are 0-indexed.
 * 
 * Implement these functions in your linked list class:
 * 
 * 
 * get(index) : Get the value of the index-th node in the linked list. If the
 * index is invalid, return -1.
 * addAtHead(val) : Add a node of value val before the first element of the
 * linked list. After the insertion, the new node will be the first node of the
 * linked list.
 * addAtTail(val) : Append a node of value val to the last element of the
 * linked list.
 * addAtIndex(index, val) : Add a node of value val before the index-th node in
 * the linked list. If index equals to the length of linked list, the node will
 * be appended to the end of linked list. If index is greater than the length,
 * the node will not be inserted. If index is negative, the node will be
 * inserted at the head of the list.
 * deleteAtIndex(index) : Delete the index-th node in the linked list, if the
 * index is valid.
 * 
 * 
 * Example:
 * 
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [1, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in LinkedList library.
 * 
 * 
 */
class Node {
public:
    int val;
    Node *next;
    Node (int n) : val(n), next(NULL) {}
};
class MyLinkedList {
private:
    Node *head, *tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= len)
            return -1;
        auto cur = head;
        while (index-- > 0)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        cur->next = head;
        head = cur;
        if (tail == NULL)
            tail = cur;
        ++len;
        /* print(); */
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = new Node(val);
        if (tail == NULL) {
            head = cur;
            tail = cur;
        }
        else {
            tail->next = cur;
            tail = tail->next;
        }
        ++len;
        /* print(); */
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len)
            return;
        else if (index <= 0)
            addAtHead(val);
        else if (index == len)
            addAtTail(val);
        else {
            Node *prev = head;
            while (--index)
                prev = prev->next;
            Node *p = new Node(val);
            p->next = prev->next;
            prev->next = p; 
            ++len;
        /* print(); */
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len)
            return;
        Node dummy(0);
        dummy.next = head;
        Node *prev = &dummy;
        int i = index;
        while (i--)
            prev = prev->next;
        Node *cur = prev->next;
        prev->next = cur->next;
        cur->~Node();
        if (index == 0)
            head = dummy.next;
        if (index == len - 1)
            tail = len == 1 ? NULL : prev;
        --len;
        /* print(); */
    }
    
    void print() {
        auto cur = head;
        while (cur)
            cout << cur->val, cur = cur->next;
        cout <<  "(tail" << tail->val << ", len" << len << ")**" << endl; 
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
