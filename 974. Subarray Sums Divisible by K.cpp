class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // step 1: initialization
        int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        // step 2: iterate through the array
        for(int i=0; i<n; i++){
            currSum = (currSum + nums[i] % k + k) % k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        // step 3: return the result
        return cnt;
    }
};
