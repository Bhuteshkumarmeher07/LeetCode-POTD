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
    int answer = 0;
    string num;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        num.push_back(root->val + '0');
        if (root->left == nullptr and root->right == nullptr) {
            answer += stoi(num);
        }

        dfs(root->left);
        dfs(root->right);

        num.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
