class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum=0;
        int n=grid.size();
        int m=grid[0].size();
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int r=i+drow[k];
                        int c=j+dcol[k];
                        if(r<n && r>=0 && c>=0 && c<m && grid[r][c]==1){
                            cnt++;
                        }
                    }
                    sum+=4-cnt;
                }
            }
        }
        return sum;
    }
};
