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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        auto comp = [](ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i])
            {
                pq.push(lists[i]);
            }
        }
        ListNode* curr = NULL;
        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();
            if(!ans)
            {
                ans = node;
                curr = node;
            }
            else
            {
                curr->next = node;
                curr = node;
            }
            if(node->next)
            {
                pq.push(node->next);
            }
        }
        return ans;
    }
};
