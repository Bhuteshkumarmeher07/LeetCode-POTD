class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>>& land, int i, int j, int n, int m, int &maxi, int &maxj) {
        if(i >= n || j >= m || land[i][j] == 0) {
            return;
        }
        land[i][j] = 0;
        maxi = max(i, maxi);
        maxj = max(j, maxj);
        helper(land, i+1, j, n, m, maxi, maxj);
        helper(land, i, j+1, n, m, maxi, maxj);
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    int maxi = i, maxj = j;
                    helper(land, i, j, n, m, maxi, maxj);
                    ans.push_back({i, j, maxi, maxj});
                }
            }
        }
        return ans;
    }
};
