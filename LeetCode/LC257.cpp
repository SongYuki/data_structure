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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;
        dfs(root, to_string(root->val));
        return result;
    }
    
    vector<string> result;
    
    void dfs(TreeNode* root, string branch){
        if (!root->left && !root->right){
            result.push_back(branch);
            return;
        }
        if (root->left) dfs(root->left,branch + "->" + to_string(root->left->val));
        if (root->right) dfs(root->right,branch + "->" + to_string(root->right->val));
        return;
    }
};
