/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (63.80%)
 * Total Accepted:    53.9K
 * Total Submissions: 84.4K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.  From left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Both of the given trees will have between 1 and 100 nodes.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        return leaf1 == leaf2;
    }
private:
    void getLeaf(TreeNode *root, vector<int> &leaf) {
        if (root == NULL)
            return;
        if (root->right == NULL && root->left == NULL)
            leaf.push_back(root->val);
        getLeaf(root->left, leaf);
        getLeaf(root->right, leaf);
        return;
    }
};
