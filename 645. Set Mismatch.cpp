class Solution {
public:
    vector<int> findErrorNums(std::vector<int>& nums) 
    {
        vector<int> arr(nums.size(), 1);
        int a1, a2;
        for (auto x : nums) 
        {
            if (arr[x-1]==1)
                arr[x-1] = 0;
            else 
            {
                a1 = x;
            }
        }
        for (int i = 0; i < nums.size(); ++i) 
        {
            if(arr[i] == 1) 
            {
                a2 = i + 1;
                break;
            }
        }
        return {a1, a2};
    }
};
