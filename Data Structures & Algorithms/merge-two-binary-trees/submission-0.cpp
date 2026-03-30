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
    TreeNode* dfs(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return nullptr;
        if(!r2) return r1;
        if(!r1) return r2;

        TreeNode* r3 = new TreeNode(r1->val + r2->val);
        r3->left = dfs(r1->left, r2->left);
        r3->right = dfs(r1->right, r2->right);
        return r3;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};