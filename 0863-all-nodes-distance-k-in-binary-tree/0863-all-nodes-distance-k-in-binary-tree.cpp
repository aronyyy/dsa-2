/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root);

        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> vis;

        q.push({target, 0});
        vis.insert(target);

        vector<int> ans;

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist == k) {
                ans.push_back(node->val);
                continue;
            }

            if (node->left && !vis.count(node->left)) {
                vis.insert(node->left);
                q.push({node->left, dist + 1});
            }

            if (node->right && !vis.count(node->right)) {
                vis.insert(node->right);
                q.push({node->right, dist + 1});
            }

            if (parent.count(node) && !vis.count(parent[node])) {
                vis.insert(parent[node]);
                q.push({parent[node], dist + 1});
            }
        }

        return ans;
    }
};