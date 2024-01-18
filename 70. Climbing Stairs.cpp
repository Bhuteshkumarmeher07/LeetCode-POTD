class Solution {
public:
// // method 1 : 
//     int climbStairs(int n) {
//         int arr[46];

//         // base conditions
//         arr[1] = 1;
//         arr[2] = 2;

//         for(int i=3; i<=n; i++) {
//             arr[i] = arr[i-1] + arr[i-2];
//         }

//         return arr[n];
//     }
    vector<int>dp;
    int solve(int n){
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n] != -1) 
            return dp[n];
        int ans = solve(n-1) + solve(n-2);
        return dp[n] = ans;
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(50,-1);
        int ans=solve(n);
        return ans;
    }
};
