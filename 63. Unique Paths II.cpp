class Solution {
public:
    int dp[101][101];
    int n, m;

    int getans(int i,int j, vector<vector<int>>&gd){
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        if(i+1 < n && gd[i+1][j]==0){
            ans += getans(i+1, j, gd);
        }
        if(j+1 < m && gd[i][j+1]==0){
            ans += getans(i, j+1, gd);
        }
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& gd) {
        memset(dp,-1, sizeof(dp));
        n = gd.size();
        m = gd[0].size();
        if(gd[0][0]==0){
            return getans(0, 0, gd);
        }
        return 0;
    }
};
