class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, zeroes = 0, index = -1;
        vector<int> ans (n, 0);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeroes++;
                index = i;
            }
            else{
                prod *= nums[i];
            }
        }
        if(zeroes > 1) {
            return ans;
        }
        else if(zeroes == 1){
            ans[index] = prod;
        }
        else{
            for(int i = 0; i < n; i++){
                ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
};
