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
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;

        int diameter = max_height(root->left) + max_height(root->right);

        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(diameter, sub);
    }

    int max_height(TreeNode* root){

        if(!root) return 0;

        return 1 + max(max_height(root->left), max_height(root->right));
    }
};
