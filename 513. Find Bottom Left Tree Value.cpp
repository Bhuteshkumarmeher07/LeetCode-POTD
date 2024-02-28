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
    void leftView(TreeNode* root,vector<int> &ans,int level)
    {
        if(root==NULL)
        return;
        if(ans.size()==level)
        ans.push_back(root->val);
        leftView(root->left,ans,level+1);
        leftView(root->right,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        leftView(root,ans,0);
        return ans[ans.size()-1];
    }
};
