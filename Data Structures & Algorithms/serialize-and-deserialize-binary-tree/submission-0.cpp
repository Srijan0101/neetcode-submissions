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

class Codec {
public:

    string join(vector<string> &res, string c){

        string s = "";
        for(auto it : res){
            s += it;
            s += c;
        }
        return s;
    }

    vector<string> split(string data, char c){

        vector<string> res;
        string s = "";
        for(auto it : data){

            if(it==c){
                res.push_back(s);
                s = "";
            }
            else{
                s += it;
            }
        }

        if(!s.empty()) res.push_back(s);

        return res;
    }

    void dfsSerialize(TreeNode* root, vector<string> &res){

        if(!root){
            res.push_back("N");
            return;
        }

        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    TreeNode* dfsDeserialize(vector<string> &t, int &i){

        if(t[i]=="N"){
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(t[i]));
        i++;
        node->left = dfsDeserialize(t, i);
        node->right = dfsDeserialize(t, i);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        vector<string> res;
        dfsSerialize(root, res);

        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> val = split(data, ',');
        int i = 0;
        return dfsDeserialize(val, i);
    }
};
