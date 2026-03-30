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
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int leftH = dfs(root->left);
        int rightH = dfs(root->right);
        return 1 + max(leftH, rightH);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
