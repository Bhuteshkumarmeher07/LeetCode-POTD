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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Stack to hold nodes for traversal
        stack<TreeNode*> stack_p, stack_q;
        
        // If either of the trees is not empty, push their roots onto the stacks
        if (p) stack_p.push(p);
        if (q) stack_q.push(q);
        
        // Continue traversal until both stacks are empty
        while (!stack_p.empty() && !stack_q.empty()) {
            // Get the top nodes from both stacks
            TreeNode *cur_p = stack_p.top();
            TreeNode *cur_q = stack_q.top();
            stack_p.pop();
            stack_q.pop();
            
            // If values of current nodes are different, trees are not the same
            if (cur_p->val != cur_q->val) return false;
            
            // Push left child nodes onto respective stacks
            if (cur_p->left) stack_p.push(cur_p->left);
            if (cur_q->left) stack_q.push(cur_q->left);
            
            // Check if the sizes of the stacks are still equal after pushing left children
            if (stack_p.size() != stack_q.size()) return false;
            
            // Push right child nodes onto respective stacks
            if (cur_p->right) stack_p.push(cur_p->right);
            if (cur_q->right) stack_q.push(cur_q->right);
            
            // Check if the sizes of the stacks are still equal after pushing right children
            if (stack_p.size() != stack_q.size()) return false;
        }
        
        // If both stacks are empty, trees are same
        return stack_p.size() == stack_q.size();
    }
};
