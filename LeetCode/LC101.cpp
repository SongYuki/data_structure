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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
    
private:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (p) {
            if (!q) return false;
            return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
        } 
        return !q;
    }
};
