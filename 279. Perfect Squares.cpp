class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the least number of perfect squares for each value up to n
        vector<int> dp(n + 1, n);
        // The least number of perfect squares for 0 is 0
        dp[0] = 0;
        // Iterate through all values from 1 to n
        for (int i = 1; i <= n; i++){
            // Iterate through all perfect squares less than or equal to i
            for (int j = 1; j * j <= i; j++){
                int s = j * j;
                // Update dp[i] with the minimum number of perfect squares
                dp[i] = min(dp[i], dp[i - s] + 1);
            }
        }
        // The result is stored in dp[n]
        return dp[n];
    }
};
