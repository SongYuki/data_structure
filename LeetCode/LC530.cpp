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
    int pre, res = INT_MAX; // pre: previous value of in-order
    int getMinimumDifference(TreeNode* root) {
        return pre = root->val-INT_MAX, InOrder(root), res;  
    }
    
    void InOrder(TreeNode* r) {
      if (r && (InOrder(r->left), res=min(res,r->val-pre))) pre=r->val, InOrder(r->right);
    }
};
