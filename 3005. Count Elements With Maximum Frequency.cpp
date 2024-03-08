class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxCount=0, n=nums.size(), count=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxCount = max(maxCount, mp[nums[i]]);
        }
        for(auto m:mp){
            if(m.second == maxCount){
                count += m.second;
            }
        }
        return count;
    }
};
