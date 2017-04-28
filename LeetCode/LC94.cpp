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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
        update(root);                                   // add root in stack
        
        for (TreeNode* cur; st.size(); update(cur->right)) {
            cur = st.top(); st.pop();                   
            ans.push_back(cur->val);                    // record leftmost value and add candidate right node in stack
        }
        
        return ans;
    }
    
private:
    stack<TreeNode*> st;
    
    void update(TreeNode* cur) {
        for (; cur; cur = cur->left) { 
            st.push(cur);                               // pushing left node into stack all the way
        }
    }
};
