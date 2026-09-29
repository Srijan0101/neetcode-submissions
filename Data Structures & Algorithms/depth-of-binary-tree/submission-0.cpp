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

    int max_length = INT_MIN;

    void func(TreeNode* root, int len){

        if(!root){
            max_length = max(max_length, len);
            return;
        }

        func(root->left, len+1);
        func(root->right, len+1);
    }

    int maxDepth(TreeNode* root) {
        
        func(root, 0);
        return max_length;
    }
};
