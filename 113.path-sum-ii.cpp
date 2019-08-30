/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (41.76%)
 * Total Accepted:    252K
 * Total Submissions: 600.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
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
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(root, sum, tmp, result);
        return result;
    }

private:
    void dfs(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int>> &result) {
        if (root == NULL)
            return;
        sum -= root->val;
        tmp.push_back(root->val);
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            result.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(root->left, sum, tmp, result);
        dfs(root->right, sum, tmp, result);
        tmp.pop_back();
        return;
    }
};
