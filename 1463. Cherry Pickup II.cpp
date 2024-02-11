class Solution {
public:
int dy[3] = {0,-1,1};
int dp[70][70][70];

int dfs(vector<vector<int>>& grid, int row, int cl1, int cl2, int n, int m){
    //base case
    if(row == n) return 0;
    //check if crossing boundary
    if(cl1<0 || cl2<0 || cl1>=m || cl2>=m) return INT_MIN;
    if(dp[row][cl1][cl2] != -1) return dp[row][cl1][cl2];

    int maxAns = 0;
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            maxAns = max(maxAns, dfs(grid, row+1, cl1+dy[i], cl2+dy[j], n,m));
        }
    }

    maxAns += (cl1==cl2) ? grid[row][cl1] : grid[row][cl1]+grid[row][cl2];
    return dp[row][cl1][cl2] = maxAns;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size(); //rows
        int m = grid[0].size();
        if(!n) return 0;

        memset(dp, -1, sizeof dp);
        //dfs(grid, row ,col1, col2,n,m )
        return dfs(grid, 0, 0, m-1, n,m);

    }
};
