/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.75%)
 * Total Accepted:    421.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorder(root, pre);            
    }
    //when in-order traverse a BST, the nodes' values increases as visiting
    //Pre node is the last node that has been visited, notice that it is a pointer reference as it keeps getting updated through the traversal
    bool inorder(TreeNode* node, TreeNode* & pre) {
        if (node == NULL) return true;
        //traverse the left subtree, check it against the pre node
        if (!inorder(node->left, pre))
            return false;
        //visiting current node, and check if this node is bigger than the last node that has been visited
        if (pre && node->val <= pre->val)
            return false;
        //always keep track of the last node that has been visited
        pre = node;
        //finally traverse the right subtree
        return inorder(node->right, pre);
    }
};
