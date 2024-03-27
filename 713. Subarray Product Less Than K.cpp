class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int left = 0; left < n; left++){
            int prod = 1;
            for(int right = left; right<n; right++){
                prod *= nums[right];
                if(prod < k) count++;
                else break;
            }
        }
        return count;

    }
};
