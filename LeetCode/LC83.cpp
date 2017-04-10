/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         if (!head) return nullptr;
	    ListNode** cur = &head->next;
	    int preVal = head->val;
	    while (*cur)
	    {
		    ListNode* entry = *cur;
		    if (entry->val == preVal)
		    {
			    *cur = entry->next;
			    //delete entry; free(entry);
		    } else {
			    preVal = entry->val;
			    cur = &entry->next;
		    }
	    }
	    return head;
    }
};

/**
* linux中的list_head和windows中的LIST_ENTRY都是双向链表的实现，两者的实现基本是等同的，和这里的单链表一样，也使用了一个dummy的头来指示链表的头尾。当dummy的头的prev/next指向dummy自身的时候，链表为空。利用dummy的头，可以避免一些不必要的判断，使代码变得精简。
使用container_of/CONTAINING_RECORD宏可以从list_head/LIST_ENTRY指针反推包含节点的数据结构。
这种实现方式简洁，高效，个人认为这种实现方式可以说是双向链表的极致了。 
**/ 
