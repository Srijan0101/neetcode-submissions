/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        // Traverse the tree
        while (curr != nullptr || !st.empty()) {
            // Reach the left-most node of the current node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // Current must be nullptr at this point
            curr = st.top();
            st.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            // We have visited the node and its left subtree. Now, it's the right subtree's turn
            curr = curr->right;
        }
        
        return -1; // Fallback, though a valid BST with k nodes will always find an answer
    }
};
