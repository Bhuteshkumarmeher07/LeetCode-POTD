class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0 or n==1) return 0;
        int i=0,j=0,count0=0,ans=0;
        while(j<n){
            if(count0==0){
                if(nums[j]==0) count0++;
                j++;
            }
            else{
                if(nums[j]==1) j++;
                else{
                    ans=max(ans,j-i-1);
                    if(nums[i]==0) count0--;
                    i++;
                }
            }
        }
        ans=max(ans,j-i-1); 
        return ans;
    }
};
