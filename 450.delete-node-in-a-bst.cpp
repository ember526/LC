/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (40.48%)
 * Total Accepted:    74.8K
 * Total Submissions: 184.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dummy(0);
        TreeNode *pred = &dummy;
        pred->left = root;
        TreeNode *cur = root;
        while (cur) {
            if (cur->val == key) {
                TreeNode *tmp = cur->left;
                if (tmp == NULL) {
                    if (pred->left == cur)
                        pred->left = cur->right;
                    else
                        pred->right = cur->right;
                    cur->~TreeNode();
                    break;
                }
                if (pred->left == cur)
                    pred->left = tmp;
                else
                    pred->right = tmp;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = cur->right;
                cur->~TreeNode();
                break;
            }
            else if (cur->val > key) {
                pred = cur;
                cur = cur->left;
            }
            else {
                pred = cur;
                cur = cur->right;
            }
        }
        return dummy.left;
    }
};
