class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int i=0,j=0,mn=INT_MAX,mx=INT_MIN,n=nums.size();
        int mxPos=-1,mnPos=-1;
        long long ans=0;
       while(j<n){
        mx=max(mx,nums[j]);
        if(nums[j]==maxK)
        mxPos=j;
        mn=min(mn,nums[j]);
        if(nums[j]==minK)
        mnPos=j;
        if(mn<minK||mx>maxK){
            mn=INT_MAX;
            mx=INT_MIN;
            i=j+1;
            mnPos=j;
            mxPos=j;
        }
        j++;
        ans+=min(mxPos,mnPos)-i+1;
       }
       return ans;
    }
};
