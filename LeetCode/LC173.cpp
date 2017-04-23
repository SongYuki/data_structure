/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* cur;
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || st.size();
    }

    /** @return the next smallest number */
    int next() {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
