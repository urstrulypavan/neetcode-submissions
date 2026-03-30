/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
    bool dfs(TreeNode* root, int curSum, int target) {
        if(!root) return false;
        curSum += root->val;
        if(!root->left && !root->right) {
            return curSum == target;
        }
        return dfs(root->left, curSum, target) || dfs(root->right, curSum, target);
    }
};