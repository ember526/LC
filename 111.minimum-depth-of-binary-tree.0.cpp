/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.72%)
 * Total Accepted:    318.5K
 * Total Submissions: 890.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        result = INT_MAX;
        if (root == NULL)
            return 0;
        dfs(root, 0);
        return result;
    }
private:
    int result;
    void dfs(TreeNode *root, int depth) {
        if (depth >= result || root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            result = depth + 1;
            return;
        }
        dfs(root->left, depth + 1),
        dfs(root->right, depth + 1);
        return;
    }
};
