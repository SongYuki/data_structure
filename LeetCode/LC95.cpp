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
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : generate(1, n);
    }
    
    vector<TreeNode*> generate(int lo, int hi) {
        vector<TreeNode*> trees;
        if (lo > hi) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> lefts = generate(lo, i - 1);
            vector<TreeNode*> rights = generate(i + 1, hi);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    trees.push_back(node);
                }
            }
        }
        
        return trees;
    }
};
