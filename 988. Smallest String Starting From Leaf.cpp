// ⠀⠀⠀⠀⠀⢀⣴⣶⣦⡄⢀⣀⣀⣀⣀⣀⢀⣴⣶⣦⣄⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣿⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣿⣿⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠙⠿⠁⠀⣠⣤⡄⠀⠀⢠⣤⣄⠀⠈⢿⠟⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠇⠀⢸⣿⣿⠳⣶⣶⡞⢿⣿⡇⢠⣼⢶⢶⣤⡀⠀⠀
// ⠀⠀⢀⣾⣿⣿⣿⣦⠈⠛⠋⠐⠤⠣⠀⠘⠛⠁⢿⡽⠛⠛⣼⡇⠀⠀
// ⠉⠉⠙⠿⢿⣿⡿⠟⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉
//

// DFS and some implementation

class Solution {
public:
    string result = "";
    void check_dfs(TreeNode* root, string curr) {
        if (!root) {
            return;
        }
        curr = char(root->val + 'a') + curr;

        if (!root->left && !root->right) {
            if (result == "" || result > curr) {
                result = curr;
            }
            return;
        }

        check_dfs(root->left, curr);
        check_dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        check_dfs(root, "");
        return result;
    }
};
