class Solution {
public:
    // Helper function to find the path from root to the target node
    bool find_path(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {
        // Base case: if node is null, path doesn't exist here
        if (!root) return false;

        // Add the current node to the path
        path.push_back(root);

        // If the current node is the target, we found the path
        if (root == target) return true;

        // Check if the target exists in the left or right subtree
        if (find_path(root->left, target, path) || find_path(root->right, target, path)) {
            return true;
        }

        // Backtrack: if target is not in this subtree, remove current node from path
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;

        // Populate the paths for both nodes
        find_path(root, p, path_p);
        find_path(root, q, path_q);

        // Compare paths from the beginning to find the last common node
        TreeNode* lca = nullptr;
        for (int i = 0; i < path_p.size() && i < path_q.size(); i++) {
            if (path_p[i] == path_q[i]) {
                lca = path_p[i]; // Update LCA as long as the paths match
            } else {
                break; // Paths diverged, stop comparing
            }
        }

        return lca;
    }
};
