/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (41.70%)
 * Total Accepted:    233.8K
 * Total Submissions: 558.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if (preorder.empty())
            return NULL;
        int rootval = preorder[0];
        TreeNode *root = new TreeNode(rootval);
        auto iter = find(inorder.begin(), inorder.end(), rootval);
        size_t lsize = iter - inorder.begin(), rsize = inorder.size() - lsize - 1;
        root->left = buildTree(vector<int> (preorder.begin() + 1, preorder.begin() + 1 + lsize), vector<int> (inorder.begin(), iter));
        root->right = buildTree(vector<int> (preorder.begin() + 1 + lsize, preorder.end()), vector<int> (iter + 1, inorder.end())); 
        return root;
    }
};
