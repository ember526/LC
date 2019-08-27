/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (35.69%)
 * Total Accepted:    8.9K
 * Total Submissions: 25K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * Given a binary tree, we install cameras on the nodes of the tree. 
 * 
 * Each camera at a node can monitor its parent, itself, and its immediate
 * children.
 * 
 * Calculate the minimum number of cameras needed to monitor all nodes of the
 * tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as
 * shown.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 1000].
 * Every node has value 0.
 * 
 * 
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
    int minCameraCover(TreeNode* root, bool hasCam = false, bool monitored =false) {
        if (root == nullptr)
            return 0;
        // Its parent decided that it should have a camera
        if (hasCam)
            return 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
        // Its parent has a camera, and it has two options
        if (monitored) {
            int nocam = minCameraCover(root->left, false, false) + minCameraCover(root->right, false, false);
            int withcam = 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
            return min(nocam, withcam);
        }
        // Its parent does not have a camera but is covered
        if (root->val)
            return root->val;
        int rootcam = 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
        int leftcam = root->left == nullptr ? INT_MAX : minCameraCover(root->left, true, false) +
                minCameraCover(root->right, false, false);
        int rightcam = root->right == nullptr ? INT_MAX : minCameraCover(root->left, false, false) +
                minCameraCover(root->right, true, false);
        return root->val = min({rootcam, leftcam, rightcam});
    }
};
