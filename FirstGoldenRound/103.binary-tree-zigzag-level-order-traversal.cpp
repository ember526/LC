/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.17%)
 * Total Accepted:    229.6K
 * Total Submissions: 543.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;    
        vector<vector<int>> result;
        if (root == NULL) 
            return result;
        q.push(root);
        bool l2r = true;
        while (q.empty() == false) {
            size_t size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                int rowi = l2r ? i : size - 1 - i;
                TreeNode *node = q.front();
                q.pop();
                    
                row[rowi] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            l2r = !l2r;
            result.push_back(row);
        }
        return result;
    }
};
