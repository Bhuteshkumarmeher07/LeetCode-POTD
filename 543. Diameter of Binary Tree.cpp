class Solution {
public:
    int findHeight(TreeNode* root, int& diameter) {
        if (root == nullptr)
            return 0;
        int leftHeight = findHeight(root->left, diameter);
        int rightHeight = findHeight(root->right, diameter);
        diameter = std::max(diameter, leftHeight + rightHeight);
        return std::max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeight(root, diameter);
        return diameter;
    }
};
