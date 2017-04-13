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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
    
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l >= r)
            return NULL;
        int index = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[index]);
        root->left = helper(nums, l, index);
        root->right = helper(nums, index + 1, r);
        return root;
    }
};
