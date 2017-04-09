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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        return rec(head, head->next);
    }
    bool rec(ListNode*& head, ListNode* cur) {
        if (cur == NULL) return true;
        else {
            bool res = rec(head, cur->next) && cur->val == head->val;
            head = head->next;
            return res;
        }
    }
};
