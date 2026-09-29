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

    ListNode* find_middle(ListNode* node){

        ListNode* slow = node;
        ListNode* fast = node;

        while(fast->next && fast->next->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse_list(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;

        while(curr){

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode* mid = find_middle(head);
        ListNode* p = mid->next;
        mid->next = NULL;

        ListNode* p2 = reverse_list(p);
        ListNode* p1 = head;

        while(p2) {
            ListNode* tmp1 = p1->next;
            ListNode* tmp2 = p2->next;

            p1->next = p2;
            p2->next = tmp1;

            p1 = tmp1;
            p2 = tmp2;
        }
    }
};
