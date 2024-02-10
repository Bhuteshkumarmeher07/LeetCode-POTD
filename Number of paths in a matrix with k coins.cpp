#dp intutive solution

long long f(vector<vector<int>>&arr,int i,int j,int k,int n, vector<vector<vector<int>>>&dp)
    {
        if(i==n-1 and j==n-1)
        return k==arr[i][j];
        if(i<0 || j<0 || i>=n ||j>=n || k<=0)
        return 0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        return dp[i][j][k]=f(arr,i,j+1,k-arr[i][j],n,dp)+f(arr,i+1,j,k-arr[i][j],n,dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return f(arr,0,0,k,n,dp);
    }
