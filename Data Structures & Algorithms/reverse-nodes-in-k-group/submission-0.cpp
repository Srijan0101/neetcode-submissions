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
    // Helper function to reverse a segment up to (but not including) node 'p'
    ListNode* reverseList(ListNode* head, ListNode* p) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while (curr != p) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // prev becomes the new head of the reversed group
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Calculate total size of the linked list
        ListNode* p = head;
        int size = 0;
        while (p) {
            size++;
            p = p->next;
        }

        // dummy node helps manage head changes seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev_group_tail = dummy;
        ListNode* curr_group_head = head;
        p = head;
        
        int count = 0;
        while (p) {
            count++;
            ListNode* next_node = p->next; // Keep track of the next node
            
            if (count == k) {
                // Reverse the current k-group segment
                ListNode* reversed_head = reverseList(curr_group_head, next_node);
                
                // Stitch the reversed group back into the main list
                prev_group_tail->next = reversed_head;
                curr_group_head->next = next_node;
                
                // Move pointers forward for the next iteration
                prev_group_tail = curr_group_head;
                curr_group_head = next_node;
                
                // Update total remaining size tracking
                size -= k;
                if (size < k) break; // If remaining nodes are less than k, leave them as-is
                
                count = 0; // Reset counter for the next group
            }
            p = next_node;
        }
        
        ListNode* new_head = dummy->next;
        delete dummy; // Clean up memory allocated for dummy
        return new_head;
    }
};
