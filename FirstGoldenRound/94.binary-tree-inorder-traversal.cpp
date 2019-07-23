/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (57.19%)
 * Total Accepted:    482.4K
 * Total Submissions: 842.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> todo;
        while (root || todo.empty() == false) {
            //Do as humans would do : always go to the most left leaf
            while (root) {
                todo.push(root);
                root = root->left;
            }
            //Just pushed into a left-most node into stack, and that was the very one to "visit" (output)
            //After visiting that node, deal with the right part of the subtree
            root = todo.top();
            todo.pop();
            result.push_back(root->val);

            root = root->right;
        }
        return result;
    }
};
