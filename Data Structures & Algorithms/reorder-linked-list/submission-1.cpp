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
    int length(ListNode* head)
    {
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        int l = length(head);
        int half = l/2;
        if(l%2 == 1)
        {
            half++;
        }
        ListNode* mid = head;
        for(int i=1;i<half;i++)
        {
            mid = mid->next;
        }
        ListNode* temp = mid->next;
        mid->next = NULL;
        temp = reverse(temp);
        ListNode* first = head;
        while(temp)
        {
            ListNode* second = first->next;
            ListNode* third = temp->next;
            first->next = temp;
            temp->next = second;
            first = second;
            temp = third;
        }
        return;
    }
};
