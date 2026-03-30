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
    int sum = 0;
    void dfs(int curSum, TreeNode* root) {
        if(!root) return;

        curSum = curSum*10 + root->val;
        if(!root->left && !root->right) {
            sum += curSum;
        }
        dfs(curSum, root->left);
        dfs(curSum, root->right);
    }
    int sumNumbers(TreeNode* root) {
        dfs(0, root);
        return sum;
    }
};