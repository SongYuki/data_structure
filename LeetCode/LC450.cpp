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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left || !root->right) {
                TreeNode* next = root->left ? root->left : root->right;
                delete root;
                return next;
            }
            TreeNode* curr = root->right;
            while(curr->left) curr = curr->left;
            root->val = curr->val;
            root->right = deleteNode(root->right, curr->val); 
        }
        return root;
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
    
    	if (key < root->val) 
        	root->left = deleteNode(root->left, key);
    	else if (key > root->val)
        	root->right= deleteNode(root->right, key);
    	else {
        	if (!root->right) {
            	TreeNode *p = root->left;
            	delete root;
            	return p;
        	}
        	else {
            	TreeNode *p = root->right;
            	while (p->left) p=p->left;
            	swap(root->val, p->val);
            	root->right=deleteNode(root->right, key);
        	}
    	}
    	return root;
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
TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode preroot(0);
        TreeNode* pre = &preroot;
        pre->right = root;

//update: nothing to say just find the node with key value
        while(root != NULL && root->val != key){    
            pre = root;
            if(root->val < key)
                root = root->right;
            else
                root = root->left;
        }
//if using this condition then the below part no necessary to check check the  root!=NULL and next != NULL
// that two is marked as '***************************'
        // if(root == NULL)
        //     return preroot.right;    
        
/*update: now we find the node with key value, then we have four situation:
*1.node has no children
*2.node only has left children
*3.node only has right children
*4. node has two children
*situation 1-3 are easy. but situation 4 is very complex. I deal with situation 4 by take the biggest value of left child.
*in order to make it easier, when the node has left subtree, I will take the biggest value of left subtree to the current node
*/


/*update:node has left children and then we get the biggest value and modified the value of the current node to the *biggest value. and then we change the problem to delete the node with biggest value in left subtree
*/
        if(root!= NULL && root->left != NULL){   //*********don't need to check root != NULL if return early
            TreeNode* del = root->left;
            pre = root;
            while(del->right != NULL){
                pre = del;
                del = del->right;
            }
            root->val = del->val;
            root = del;
        }
    

// update: now the node which need to delete only has two situation
//update:1.node has no children
//update:2.node only has left children 
    TreeNode* next = root;
        if(next != NULL && next->left != NULL)  //*********don't need to check next != NULL if return early      
            next = next->left;
        else if(next != NULL)
            next = next->right;

        
        if(pre->left == root)
            pre->left = next;
        else
            pre->right = next;
        return preroot.right;

        
    }
