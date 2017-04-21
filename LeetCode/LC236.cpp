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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)  return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        
        /** find the LCA lowest parent **/
        if(left && right)  return root;
        /** this ensures that the LCA is the lowest **/
        /** as we just pass the LCA result back-track **/
        if(!left)  return right;
        if(!right)  return left;
    }
};
