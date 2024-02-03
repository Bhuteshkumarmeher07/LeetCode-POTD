#include<bits/stdc++.h>
int f(int ind, vector<int> &arr, int k,vector<int> &dp)
{
    int n= arr.size();
    if(ind == arr.size()) 
    return 0;
    if(dp[ind] != -1)
    return dp[ind];
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for(int j = ind; j < min(ind+k,n);j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + f(j+1,arr,k,dp);
        maxAns = max(maxAns,sum);
    }
    return dp[ind]=maxAns;
}
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k,dp);
    }
};
