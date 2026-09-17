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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = NULL;
        ListNode* second = head;
        int count = 0;
        while(second && count < n)
        {
            second = second->next;
            count++;
        }
        while(second)
        {
            if(!first)
                first = head;
            else
                first = first->next;
            second = second->next;
        }
        if(first == NULL)
        {
            return head->next;
        }
        ListNode* temp = first->next;
        if(temp)
        {
            first->next = temp->next;
            temp->next = NULL;
        }
        return head;
    }
};
