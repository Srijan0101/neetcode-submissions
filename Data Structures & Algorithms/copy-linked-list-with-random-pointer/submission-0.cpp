/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* curr = head;
        while(curr){

            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;

            curr = curr->next->next;
        }

        curr = head;
        while(curr){

            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* dummy = new Node(0);
        Node* p = dummy;

        curr = head;

        while (curr) {
            Node* copy = curr->next;        // 1. Save pointer to the cloned node
            curr->next = copy->next;        // 2. Restore original list link
            
            p->next = copy;                 // 3. Append cloned node to new list
            p = copy;                       // 4. Move clone pointer forward
            
            curr = curr->next;              // 5. Move original pointer forward
        }
        return dummy->next;
    }
};
