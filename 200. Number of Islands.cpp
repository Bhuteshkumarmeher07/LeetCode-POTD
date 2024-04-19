class Solution {
public:
    int n;
    int m;

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i == n || j < 0 || j == m) return;
        
        int row_trav[] = {-1, 0, 1, 0};
        int col_trav[] = {0, -1, 0, 1};

        if (grid[i][j] == '1'){
            grid[i][j] = '2';
            for (int k = 0; k < 4; k++) {
                dfs(grid, i + row_trav[k], j + col_trav[k]);
            }
        } 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
