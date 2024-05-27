class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int cnt = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] >= cnt){
                cnt++;
                if(cnt > nums[i]){
                    return -1;
                }
            }
            else{
                return cnt;
            }
        }
        return n;
    }
};
