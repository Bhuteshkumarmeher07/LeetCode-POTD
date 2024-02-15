#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll prefSum = nums[0] + nums[1];
        ll ans = 0;

        for(int i=2; i<nums.size(); i++){
            if(prefSum > nums[i]){
                ans = max(ans, prefSum + nums[i]);
            }
            prefSum += nums[i];
        }
        if(ans == 0){
            return -1;
        }
        else{
            return ans;
        }
    }
// TC = O(n + logn)
// SC = O(logn)
};
