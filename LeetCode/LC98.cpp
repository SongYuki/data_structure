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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};



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
    bool isValidBST(TreeNode* root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    while(l&&l->right){l=l->right;}
    while(r&&r->left){r=r->left;}
    if(root->left && (root->val <= l->val)) return false;  
    if(root->right && (root->val >= r->val)) return false;  
    return isValidBST(root->left)&&isValidBST(root->right);
    }
    
};
