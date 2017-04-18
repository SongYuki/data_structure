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
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
    
private:
    int ans = 0;
    int maxDepth (TreeNode* root) {
        if (!root) return 0;
        int L = maxDepth(root->left), R = maxDepth(root->right);
        ans = max(ans, L + R);
        return 1 + max(L, R);
  }
};
