/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (42.03%)
 * Total Accepted:    112.2K
 * Total Submissions: 266.9K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        int target = getHeight(t);
        getPeers(s, target);
        for (auto peer : peers)
            if (isSame(peer, t))
                return true;
        return false;
    }
private:
    vector<TreeNode *> peers;
    int getHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int getPeers(TreeNode *node, int target) {
        if (node == NULL)
            return 0;
        int height = 1 + max(getPeers(node->left, target), getPeers(node->right, target));
        if (height == target)
            peers.push_back(node);
        return height;
    }

    bool isSame(TreeNode *root, TreeNode *target) {
        if (root == NULL && target == NULL)
            return true;
        if (root == NULL || target == NULL)
            return false;
        return (root->val == target->val) && isSame(root->left, target->left) && isSame(root->right, target->right);
    }
};
