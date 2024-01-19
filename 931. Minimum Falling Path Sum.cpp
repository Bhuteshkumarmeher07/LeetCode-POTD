class Solution {
    bool is_valid(int i,int j,vector<vector<int>>& matrix){
        return (i>0 && j>0 && i<matrix.size()+1 && j<matrix.size()+1);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<n+1;i++) 
           dp[n][i]=matrix[n-1][i-1];
        
        for(int i=n-1;i>0;i--){
            for(int j=n;j>0;j--){
               dp[i][j]=dp[i+1][j];
            if(is_valid(i+1,j+1,matrix))   
               dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
            if(is_valid(i+1,j-1,matrix))   
               dp[i][j]=min(dp[i+1][j-1],dp[i][j]);
               dp[i][j]+=matrix[i-1][j-1];
            }
        }
        for(int i=1;i<n+1;i++) 
            ans=min(ans,dp[1][i]);
        return ans;
    }
};
