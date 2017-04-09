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
        bool ans = true;
        vector<int> nums;
        while(head != NULL)
        {
            nums.push_back(head -> val);
            head = head -> next;
        }
        for(int i = 0; i < nums.size() / 2; i++)
            if(nums[i] != nums[nums.size() - i -1]) ans = false;
            return ans;
    }
};
