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
    // **ans** contains the result.
    vector<int> ans;
   // **cur** variable is the cur occurrence, **occ** variable is the max occurrence.
    int cur = 0, occ = 0;
    // **pre** variable is the previous node address, we do inorder travel.
    TreeNode* pre = NULL;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        // this step give of the occurrence  of root->val.
        if(!pre || pre->val != root->val) cur = 1;
        else cur++;
        //if cur == occ, we just add root->val to our ans, if(cur > occ), ans = {root->val}.
        if(cur >= occ) {
            if(cur > occ) {ans = {}; occ = cur; }
            ans.push_back(root->val);
        }
        pre = root;
        inorder(root->right);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
