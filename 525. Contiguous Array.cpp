class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;//difference points to index
        int countZero = 0;
        int countOne = 0;
        int maxlen = 0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == 0)
                countZero++;
            else if (nums[i] == 1)
                countOne++;
            if (countZero == countOne)
                maxlen = max(maxlen,i+1);
            else if (countZero != countOne){
                int diff = countZero - countOne;
                if (mp.find(diff) != mp.end())
                    maxlen = max(maxlen,i-mp[diff]);
                else if (mp.find(diff) == mp.end())
                    mp[diff] = i;
            }
        }
        return maxlen;
    }
};
