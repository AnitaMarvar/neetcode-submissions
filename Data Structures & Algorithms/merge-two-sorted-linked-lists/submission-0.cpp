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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        ListNode *temp = list1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = list2;
        vector<int>arr;
        ListNode *temp1 = list1;
        while(temp1 != NULL)
        {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        sort(arr.begin(),arr.end());

        temp1 = list1;
        for(int i=0;i<arr.size();i++)
        {
            temp1->val = arr[i];
            temp1=temp1->next;
        }
        return list1;
    }
};
