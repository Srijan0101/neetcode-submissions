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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> v(101, -101);

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){

            int n = q.size();
            while(n--){

                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();

                if(node){
                    v[level] = node->val;
                    q.push({node->left, level+1});
                    q.push({node->right, level+1});
                }
            }
        }

        vector<int> res;
        for(auto it : v){
            if(it!=-101) res.push_back(it);
        }

        return res;
    }
};
