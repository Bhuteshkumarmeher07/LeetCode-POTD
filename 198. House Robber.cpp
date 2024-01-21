class Solution {
public:
// sol-1
    // int robHelper(vector<int>& nums, int i)
    // {
    //     // base case
    //     if(i >= nums.size())
    //     {
    //         return 0;
    //     }
    //     // lets solve 1 case
    //     int robAmt1 = nums[i] + robHelper(nums, i+2);
    //     int robAmt2 = 0 + robHelper(nums, i+1);
         
    //     // baki sab RE sambhal lega 
    //     return max(robAmt1, robAmt2);
    // }


    // int rob(vector<int>& nums) {
    //     return robHelper(nums, 0);
    //}

//sol-2    
    int solve(vector<int> &nums, int size, int index){
        // base case
        if(index >= size){
            return 0;
        }
        // chori krlo -> ith index par
        int option1 = nums[index] + solve(nums, size, index+2);

        // chori mat karo -> ith index par
        int option2 = 0 + solve(nums, size, index+1);

        // return the maximum amount 
        int finalAns = max(option1,option2);
        return finalAns;
    }

    int rob(vector<int> &nums){
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;
    }
};
