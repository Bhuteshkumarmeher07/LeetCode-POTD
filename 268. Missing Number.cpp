class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xorr = 0;

        for(int i = 0; i<=nums.size(); i++){
            Xorr = Xorr^i;
        }

        for(int i = 0; i<nums.size(); i++){
            Xorr = Xorr^nums[i];
        }

        return Xorr;
    }
};
