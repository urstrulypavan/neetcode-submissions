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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val < q->val) return root;
        if(root->val < p->val && root->val > q->val) return root;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        if(p->val < root->val && q->val < root->val) {
            return dfs(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val) {
            return dfs(root->right, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
