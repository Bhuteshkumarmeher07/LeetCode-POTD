/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        // level order
        queue<TreeNode*> q;
        q.push(root);
        bool inc = true;
        int prev = INT_MIN;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* front = q.front();
                q.pop();
                // cout << "prev " << prev << ",";
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                if ((inc && prev < front->val && front->val % 2 == 1) ||
                    (!inc && prev > front->val && front->val % 2 == 0)) {
                    prev = front->val;
                } else {
                    return false;
                }
            }
            // cout << "\n";
            if (inc)
                prev = INT_MAX;
            else
                prev = INT_MIN;
            inc = !inc;
        }

        return true;
    }
};
