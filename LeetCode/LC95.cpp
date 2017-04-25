/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //Shallow Copy - TreeNodes are shared between trees: 
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

//Deep Copy - All trees use its own nodes:
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : generate(1, n);
    }

private:
    vector<TreeNode*> generate(int lo, int hi) {
        vector<TreeNode*> trees;
        if (lo > hi) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int k = lo; k <= hi; k++) {
            vector<vector<TreeNode*>> lefts(1, generate(lo, k - 1));
            vector<vector<TreeNode*>> rights(1, generate(k + 1, hi));
            int l = lefts[0].size(), r = rights[0].size();
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < r; j++) {
                    if (j >= lefts.size()) lefts.push_back(generate(lo, k - 1));
                    if (i >= rights.size()) rights.push_back(generate(k + 1, hi));
                    TreeNode* node = new TreeNode(k);
                    node->left = lefts[j][i];
                    node->right = rights[i][j];
                    trees.push_back(node);
                }
            }
        }

        return trees;
    }
};



//Clone

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
            // TreeNode in this vector should only be used while combining with the first TreeNode in rights, for the rest use clone;
            vector<TreeNode*> lefts = generate(lo, i - 1);
            for (TreeNode* left : lefts) {
                vector<TreeNode*> rights = generate(i + 1, hi);
                bool first = true;
                for (TreeNode* right : rights) {
                    TreeNode* node = new TreeNode(i);
                    node->left = first ? left : clone(left);    // the first node in rights use left, other use cloned left;
                    node->right = right;
                    trees.push_back(node);
                    first = false;
                }
            }
        }
        
        return trees;
    }

private:
    /* Check null both at node and left,right */
    TreeNode* clone(TreeNode* node) {
        if (!node) {
            return nullptr;
        }
        TreeNode* copy = new TreeNode(node->val);
        if (node->left) {
            copy->left = clone(node->left);
        }
        if (node->right) {
            copy->right = clone(node->right);
        }
        return copy;
    }
};





