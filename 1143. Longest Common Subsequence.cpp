class Solution {
private:
  int solveTopDown( int n, int m, string text1, string text2)
  {
        int dp[n+1][m+1];
 
    for( int i{0};i<n+1;i++)
    {
        for( int j=0;j<=m;j++)
        {
            if(i==0||j==0) dp[i][j]=0;
          if(i>=1 && j>=1){  if(text1[i-1]==text2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
          }
        }
    } return dp[n][m];
  }

 int memo( int n, int m, string a, string b,vector<vector<int>>&dp)
 { 
     if(n==0||m==0) return 0;
     if(dp[n][m]!=-1)return dp[n][m];
     if(a[n-1]==b[m-1])
     return dp[n][m]=1+memo(n-1,m-1,a,b,dp);
     else
     return dp[n][m]= max(memo(n-1,m,a,b,dp),memo(n,m-1,a,b,dp));
 }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>>dp(n+1,(vector<int>(m+1,-1)));
        // return memo(n,m,text1,text2,dp);
        return solveTopDown(n,m,text1,text2);

    }
};
