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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=head,*p2=head,*p=NULL;
        while(p2 && p2->next)
        {
            p1= p1->next;
            p2= p2->next->next;
            if(p1== p2)   /* find cycle*/
            {
                p2= head; /* head and p1 have the same distance from the cycle begins*/
                while(p2!=p1) /* find the cycle begin node if p1==p2*/
                {
                    p1= p1->next;
                    p2= p2->next;
                }
                p= p1;
                break;
            }
        }
        return p;
    }
};
