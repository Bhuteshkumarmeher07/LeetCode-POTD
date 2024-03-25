class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        bool lastNumber = false;
        for (int i = 0 ; i < nums.size(); ++i){
            int temp = abs(nums[i]);
            if (nums[temp-1] < 0){
                answer.push_back(temp);
            }
            else{
                nums[temp-1] *= -1;
            }
        }

        return answer;
    }
};
