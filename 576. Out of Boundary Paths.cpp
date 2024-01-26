class Solution {
public:
    int dp[51][51][51];
    long int mod = 1e9+7;
    int dfs(int m , int n , int maxMove, int sr , int sc)
    {
        if(sr<0 || sr>=m || sc<0 || sc>=n) {
            return 1;
        }
        if(maxMove<=0) return 0;

        if(dp[sr][sc][maxMove]!=-1) return dp[sr][sc][maxMove];

        return dp[sr][sc][maxMove]=(
            dfs(m,n,maxMove-1,sr-1,sc)%mod +   
            dfs(m,n,maxMove-1,sr+1,sc)%mod +   
            dfs(m,n,maxMove-1,sr,sc-1)%mod +   
            dfs(m,n,maxMove-1,sr,sc+1)%mod)%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 , sizeof(dp));

        return dfs(m,n,maxMove,startRow,startColumn);
    }
};
