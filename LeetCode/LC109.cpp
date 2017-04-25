//	Definition for singly-linked list.
struct ListNode{
		int val;
		ListNode *next;
		ListNode(int x):val(x),next(NULL){}
	};

//	Definition for a binary tree node
struct TreeNode{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x):val(x),left(NULL),right(NULL){}
	};
class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head==NULL)
		{
			return NULL;
		}

		if (head->next==NULL)
		{
			return new TreeNode(head->val);
		}
		ListNode* slow = head;
		ListNode* fast = head->next->next;
		while (fast&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* rightList = slow->next->next;
		TreeNode* root = new TreeNode(slow->next->val);
		slow->next = NULL;
		root->left = sortedListToBST(head);
		root->left = sortedListToBST(rightList);
		return root;
	}
};

