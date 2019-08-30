/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (38.44%)
 * Total Accepted:    344.6K
 * Total Submissions: 894.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        vector<TreeNode *> layer;
        if (root == NULL)
            return false;
        layer.push_back(root);
        while (layer.empty() == false) {
            vector<TreeNode *> next;
            for (auto node : layer) {
                if (node->val == sum && node->left == NULL && node->right == NULL)
                    return true;
                if (node->left) {
                    node->left->val += node->val;
                    next.push_back(node->left);
                }
                if (node->right) {
                    node->right->val += node->val;
                    next.push_back(node->right);
                }
            }
            layer.swap(next);
        }
        return false;
    }
};
