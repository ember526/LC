/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (47.84%)
 * Total Accepted:    244.2K
 * Total Submissions: 509.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> layer;
        if (root == NULL)
            return result;
        layer.push_back(root);
        while (layer.empty() == false) {
            vector<TreeNode *>next;
            vector<int> tmp;
            for (auto node : layer) {
                tmp.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }
            layer.swap(next);
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
