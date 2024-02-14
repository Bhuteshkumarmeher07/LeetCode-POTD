class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // method 1 : 2 pass
        // store positive and -ve in new vector
        // TC - O(n+n)

        // method 2 : Two pointer approach : 1 pass
        // here i will create only a new ANS vector
        // TC = O(n), SC = O(1)
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;

        // method 3 : In place 
        // here we cant use the ans vector
        // If order doesnt matter
        // int n = nums.size();
        // int positive = 0, neg = 1;
        // while(positive < n && neg < n){
        //     if(nums[positive] > 0) positive += 2;
        //     else if(nums[neg] < 0) neg += 2;
        //     else{
        //         swap(nums[positive], nums[neg]);
        //     }
        // }
        // return nums;
    }
};
