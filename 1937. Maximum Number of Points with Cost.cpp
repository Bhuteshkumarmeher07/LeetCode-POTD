class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        // Initialize DP with the first row
        vector<long long> dp(points[0].begin(), points[0].end());
        
        // Iterate over each row
        for (int i = 1; i < m; ++i) {
            // Update DP for the current row

            // Update left-to-right max values in DP
            for (int j = 1; j < n; ++j) {
                dp[j] = max(dp[j], dp[j - 1] - 1);
            }

            // Update right-to-left max values in DP
            for (int j = n - 2; j >= 0; --j) {
                dp[j] = max(dp[j], dp[j + 1] - 1);
            }

            // Add current row's points to DP
            for (int j = 0; j < n; ++j) {
                dp[j] += points[i][j];
            }
        }
        
        // Return the maximum value from the last dp row
        return *max_element(dp.begin(), dp.end());
    }
};
