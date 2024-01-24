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
int result =0;
void solve(TreeNode*root,vector<int>&freq){
    if(root==NULL){
        return ;
    }
    freq[root->val]++;//counting frequency 
    if(root->left==NULL && root->right==NULL){
        int oddfreq =0;
        for(int i=1;i<=9;i++){
            if(freq[i]%2!=0){
                oddfreq++; //counting frequency which is coming odd time
            }
        }
        if(oddfreq<=1){
            result++; //adding only those which is coming odd time but onely one time
        }
    }
    solve(root->left,freq);
    solve(root->right,freq);
    freq[root->val]--; // because we have passed it using byreference
}
    int pseudoPalindromicPaths (TreeNode* root) {
       vector<int>freq(10,0);//to store the frequency
       solve(root,freq);
       return result;

        
    }
};
