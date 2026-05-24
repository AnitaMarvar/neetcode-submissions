/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==NULL)return false;
        if(head->next == NULL)return false;

        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && slow != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
