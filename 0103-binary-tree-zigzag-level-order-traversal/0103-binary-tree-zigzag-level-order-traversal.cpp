class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool leftToRight = true;

        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : n - 1 - i;
                level[index] = curr->val;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};