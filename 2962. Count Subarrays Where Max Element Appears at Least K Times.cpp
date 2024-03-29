class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mxEle=nums[0];
        for(auto i:nums){
            mxEle=max(mxEle,i);
        }

        int i=0;
        int n=nums.size();
        long long cnt=0;
        int freq=0;

        for(int j=0;j<n;j++){
            if(nums[j]==mxEle){
                freq++;
            }

            while(freq==k){
                cnt+=(n-j);
                if(nums[i]==mxEle){
                    freq--;
                }
                i++;
            }
        }
        return cnt;
    }
};
