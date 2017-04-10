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
* linux�е�list_head��windows�е�LIST_ENTRY����˫�������ʵ�֣����ߵ�ʵ�ֻ����ǵ�ͬ�ģ�������ĵ�����һ����Ҳʹ����һ��dummy��ͷ��ָʾ�����ͷβ����dummy��ͷ��prev/nextָ��dummy�����ʱ������Ϊ�ա�����dummy��ͷ�����Ա���һЩ����Ҫ���жϣ�ʹ�����þ���
ʹ��container_of/CONTAINING_RECORD����Դ�list_head/LIST_ENTRYָ�뷴�ư����ڵ�����ݽṹ��
����ʵ�ַ�ʽ��࣬��Ч��������Ϊ����ʵ�ַ�ʽ����˵��˫������ļ����ˡ� 
**/ 
