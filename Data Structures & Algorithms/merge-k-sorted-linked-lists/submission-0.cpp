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

        if(lists.size()==0) return NULL;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        for(int i = 0; i < lists.size(); i++){

            ListNode* p = lists[i];
            if(p) pq.push({p->val, p});
        }

        while(!pq.empty()){

            ListNode* node = pq.top().second;
            ListNode* p = node;
            pq.pop();
            if(p->next){
                pq.push({p->next->val, p->next});
            }

            ptr->next = node;
            ptr = ptr->next;
        }

        return dummy->next;
    }
};
